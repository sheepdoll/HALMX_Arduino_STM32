/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "UARTClass.h"

uint8_t r_byte;
uint8_t temp;

// Constructors ////////////////////////////////////////////////////////////////

UARTClass::UARTClass( UART_HandleTypeDef *pUart, IRQn_Type dwIrq, uint32_t dwId, RingBuffer *pRx_buffer, RingBuffer *pTx_buffer )
{
  _usartNumber = USART1; //In this case create by default the USART1 serial port.
  _rx_buffer = pRx_buffer;
  _tx_buffer = pTx_buffer;
  _pUart=pUart;
  _dwIrq=dwIrq;
  _dwId=dwId;
}

 /**
  * Additional constructor by Vassilis Serasidis
  * 
  */
UARTClass::UARTClass( UART_HandleTypeDef *pUart, IRQn_Type dwIrq, uint32_t dwId, RingBuffer *pRx_buffer, RingBuffer *pTx_buffer, USART_TypeDef* usartNumber )
{
  _rx_buffer = pRx_buffer;
  _tx_buffer = pTx_buffer;

  _pUart=pUart;
  _dwIrq=dwIrq;
  _dwId=dwId;
  _usartNumber = usartNumber;
}
// Public Methods //////////////////////////////////////////////////////////////

void UARTClass::begin(const uint32_t dwBaudRate)
{
  begin(dwBaudRate, Mode_8N1);
}

void UARTClass::begin(const uint32_t dwBaudRate, const UARTModes config)
{
  uint32_t modeReg = 0;//static_cast<uint32_t>(config) & 0x00000E00;
  init(dwBaudRate, modeReg);  
} 

void UARTClass::init(const uint32_t dwBaudRate, const uint32_t modeReg)
{
  /** Configure baudrate (asynchronous, no oversampling)
   *  02 March 2016 by Vassilis Serasidis
   */
  _pUart->Instance = _usartNumber;
  _pUart->Init.BaudRate = dwBaudRate;
  _pUart->Init.WordLength = UART_WORDLENGTH_8B;
  _pUart->Init.StopBits = UART_STOPBITS_1;
  _pUart->Init.Parity = UART_PARITY_NONE;
  _pUart->Init.Mode = UART_MODE_TX_RX;
  _pUart->Init.HwFlowCtl = UART_HWCONTROL_NONE;
  _pUart->Init.OverSampling = UART_OVERSAMPLING_16;


  // Configure interrupts
  // Enable UART interrupt in NVIC  when we have enough info for bridge
  NVIC_EnableIRQ(_dwIrq);

  // Make sure both ring buffers are initialized back to empty.
  _rx_buffer->_iHead = _rx_buffer->_iTail = 0;
  _tx_buffer->_iHead = _tx_buffer->_iTail = 0;

  /** Enable receiver and transmitter
   *  02 March 2016 by Vassilis Serasidis
   */
  HAL_UART_Init(_pUart);
  
  HAL_UART_Receive_IT(_pUart, (uint8_t *)&r_byte, 1);
}

void UARTClass::end( void )
{
  // Clear any received data
  _rx_buffer->_iHead = _rx_buffer->_iTail;

  // Wait for any outstanding data to be sent
  flush();

  // Disable UART interrupt in NVIC
  NVIC_DisableIRQ( _dwIrq );

}

/* void UARTClass::setInterruptPriority(uint32_t priority)
{
//  NVIC_SetPriority(_dwIrq, priority & 0x0F);
} */

uint32_t UARTClass::getInterruptPriority()
{
  return NVIC_GetPriority(_dwIrq);
}

int UARTClass::available( void )
{
  return (uint32_t)(SERIAL_BUFFER_SIZE + _rx_buffer->_iHead - _rx_buffer->_iTail) % SERIAL_BUFFER_SIZE;
}

int UARTClass::availableForWrite(void)
{
  int head = _tx_buffer->_iHead;
  int tail = _tx_buffer->_iTail;
  if (head >= tail) return SERIAL_BUFFER_SIZE - 1 - head + tail;
  return tail - head - 1;
}

int UARTClass::peek( void )
{
  if ( _rx_buffer->_iHead == _rx_buffer->_iTail )
    return -1;

  return _rx_buffer->_aucBuffer[_rx_buffer->_iTail];
}

int UARTClass::read( void )
{
  // if the head isn't ahead of the tail, we don't have any characters
  if ( _rx_buffer->_iHead == _rx_buffer->_iTail )
    return -1;

  uint8_t uc = _rx_buffer->_aucBuffer[_rx_buffer->_iTail];
  _rx_buffer->_iTail = (unsigned int)(_rx_buffer->_iTail + 1) % SERIAL_BUFFER_SIZE;
  return uc;
}

void UARTClass::flush( void )
{
  while (_tx_buffer->_iHead != _tx_buffer->_iTail); //wait for transmit data to be sent
  // Wait for transmission to complete

}

size_t UARTClass::write( const uint8_t uc_data )
{
#if 0
  // Is the hardware currently busy?
  if (((_pUart->UART_SR & UART_SR_TXRDY) != UART_SR_TXRDY) |
      (_tx_buffer->_iTail != _tx_buffer->_iHead))
  {
    // If busy we buffer
    unsigned int l = (_tx_buffer->_iHead + 1) % SERIAL_BUFFER_SIZE;
    while (_tx_buffer->_iTail == l)
      ; // Spin locks if we're about to overwrite the buffer. This continues once the data is sent

    _tx_buffer->_aucBuffer[_tx_buffer->_iHead] = uc_data;
    _tx_buffer->_iHead = l;
    // Make sure TX interrupt is enabled
    _pUart->UART_IER = UART_IER_TXRDY;
  }
  else 
  {
     // Bypass buffering and send character directly

  }
#endif
  while (HAL_UART_Transmit_IT(_pUart, (uint8_t *)&uc_data, 1) == HAL_BUSY); //Wait here if serial bus is busy.
  HAL_UART_Transmit_IT(_pUart, (uint8_t *)&uc_data, 1);
  //HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_1); //Toggle the state of pin PA1. Just for debuging purpose.
  return 1;
}

/************************************************
 * 02 March 2016 by Vassilis Serasidis
 */
void UARTClass::RxHandler (void){
  if(availableForWrite() > 0){ //If there is empty space in rx_buffer, read a byte from the Serial port and save it to the buffer.
    _rx_buffer->store_char(r_byte);
    HAL_UART_Receive_IT(_pUart, (uint8_t *)&r_byte, 1);
  }
}

/************************************************
 * 02 March 2016 by Vassilis Serasidis
 */
void UARTClass::TxHandler(void){
  
}