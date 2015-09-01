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

#include "arduino.h"
//#include "variant.h"


/*

Position	Name			Type	Signal		Label
	1		VBAT			Power	
	2		PC13-TAMPER-RTC	Output	GPIO_Output
	3		PC14-OSC32_IN	I/O
	4		PC15-OSC32_OUT	I/O
	5		PD0-OSC_IN		I/O		RCC_OSC_IN
	6		PD1-OSC_OUT		I/O		RCC_OSC_OUT
	7		NRST			Reset
	8		VSSA			Power
	9		VDDA			Power
	10		PA0-WKUP		I/O
	11		PA1				I/O
	12		PA2				I/O
	13		PA3				I/O
	14		PA4				I/O		SPI1_NSS	SPI1_NSS (opt)
	15		PA5				I/O		SPI1_SCK
	16		PA6				I/O		SPI1_MISO
	17		PA7				I/O		SPI1_MOSI
	18		PB0				I/O
	19		PB1				Output	GPIO_Output	Blue_LED
	20		PB2				I/O
	21		PB10			I/O
	22		PB11			I/O
	23		VSS				Power
	24		VDD				Power
	25		PB12			I/O
	26		PB13			I/O
	27		PB14			I/O
	28		PB15			I/O
	29		PA8				I/O
	30		PA9				I/O		USART1_TX
	31		PA10			I/O		USART1_RX
	32		PA11			I/O
	33		PA12			I/O
	34		PA13			I/O		SYS_JTMS-SWDIO
	35		VSS				Power
	36		VDD				Power
	37		PA14			I/O		SYS_JTCK-SWCLK
	38		PA15			I/O
	39		PB3				I/O
	40		PB4				I/O
	41		PB5				I/O
	42		PB6				I/O		I2C1_SCL
	43		PB7				I/O		I2C1_SDA
	44		BOOT0			Boot
	45		PB8				I/O		CAN_RX
	46		PB9				I/O		CAN_TX
	47		VSS				Power
	48		VDD				Power


 * DUE Board pin   |  PORT  | Label
 * ----------------+--------+-------
 *   0             |  PA8   | "RX0"
 *   1             |  PA9   | "TX0"
 *   2       TIOA0 |  PB25  |
 *   3       TIOA7 |  PC28  |
 *   4       NPCS1 |  PA29  |
 *           TIOB6 |  PC26  |
 *   5       TIOA6 |  PC25  |
 *   6       PWML7 |  PC24  |
 *   7       PWML6 |  PC23  |
 *   8       PWML5 |  PC22  |
 *   9       PWML4 |  PC21  |
 *  10       NPCS0 |  PA28  |
 *           TIOB7 |  PC29  |
 *  11       TIOA8 |  PD7   |
 *  12       TIOB8 |  PD8   |
 *  13       TIOB0 |  PB27  | LED AMBER "L"
 *  14       TXD3  |  PD4   | "TX3"
 *  15       RXD3  |  PD5   | "RX3"
 *  16       TXD1  |  PA13  | "TX2"
 *  17       RXD1  |  PA12  | "RX2"
 *  18       TXD0  |  PA11  | "TX1"
 *  19       RXD0  |  PA10  | "RX1"
 *  20             |  PB12  | "SDA"
 *  21             |  PB13  | "SCL"
 *  22             |  PB26  |
 *  23             |  PA14  |
 *  24             |  PA15  |
 *  25             |  PD0   |
 *  26             |  PD1   |
 *  27             |  PD2   |
 *  28             |  PD3   |
 *  29             |  PD6   |
 *  30             |  PD9   |
 *  31             |  PA7   |
 *  32             |  PD10  |
 *  33             |  PC1   |
 *  34             |  PC2   |
 *  35             |  PC3   |
 *  36             |  PC4   |
 *  37             |  PC5   |
 *  38             |  PC6   |
 *  39             |  PC7   |
 *  40             |  PC8   |
 *  41             |  PC9   |
 *  42             |  PA19  |
 *  43             |  PA20  |
 *  44             |  PC19  |
 *  45             |  PC18  |
 *  46             |  PC17  |
 *  47             |  PC16  |
 *  48             |  PC15  |
 *  49             |  PC14  |
 *  50             |  PC13  |
 *  51             |  PC12  |
 *  52       NPCS2 |  PB21  |
 *  53             |  PB14  |
 *  54             |  PA16  | "A0"
 *  55             |  PA24  | "A1"
 *  56             |  PA23  | "A2"
 *  57             |  PA22  | "A3"
 *  58       TIOB2 |  PA6   | "A4"
 *  69             |  PA4   | "A5"
 *  60       TIOB1 |  PA3   | "A6"
 *  61       TIOA1 |  PA2   | "A7"
 *  62             |  PB17  | "A8"
 *  63             |  PB18  | "A9"
 *  64             |  PB19  | "A10"
 *  65             |  PB20  | "A11"
 *  66             |  PB15  | "DAC0"
 *  67             |  PB16  | "DAC1"
 *  68             |  PA1   | "CANRX"
 *  69             |  PA0   | "CANTX"
 *  70             |  PA17  | "SDA1"
 *  71             |  PA18  | "SCL1"
 *  72             |  PC30  | LED AMBER "RX"
 *  73             |  PA21  | LED AMBER "TX"
 *  74       MISO  |  PA25  |
 *  75       MOSI  |  PA26  |
 *  76       SCLK  |  PA27  |
 *  77       NPCS0 |  PA28  |
 *  78       NPCS3 |  PB23  | unconnected!
 *
 * USB pin         |  PORT
 * ----------------+--------
 *  ID             |  PB11
 *  VBOF           |  PB10
 *
 */


#ifdef __cplusplus
extern "C" {
#endif

/*

 * Pins descriptions

 this is reworked to be a bit more abstract.  The main use of this array is for
 bit banged GPIO setup.  Since we are using the HAL libraries, the setup
 is through STM32CubeMX for our peripherals, rendering this table
 redundant for general io and peripheral setup
 
 What we have here is an Abstraction on top of another abstraction. 
 
 The abstraction is that to set or read a pin we only need two items of
 information, the port and the pin.  As Arduino abstracts by pin
 we use this abstraction to map into the following table the order
 of this table should be by Arduino D number

 The only thing the HAL API needs are the port and PIN references

 The following table is written in c shorthand it could also be set up
 with the more readable 
 
 g_Pin2PortMapArray[D1 ].GPIOx_Port = GPIOA;
 g_Pin2PortMapArray[D1 ].Pin_abstraction = GPIO_PIN_3    D0/PA3	USART_RX	 
 g_Pin2PortMapArray[D2 ].GPIOx_Port = GPIOA;
 g_Pin2PortMapArray[D2].Pin_abstraction = GPIO_PIN_2    D0/PA3	USART_RX
 ... ect ...
 Ideally this array should be non mutable and in flash	 

 
*/


/* Quick and dirty table based on Maple Mini schematic */
extern const Pin2PortMapArray g_Pin2PortMapArray[]=
{    

    {GPIOB, GPIO_PIN_11	},	/* USART3_RX	*/
    {GPIOB, GPIO_PIN_10	},	/* USART3_TX	*/
    {GPIOB, GPIO_PIN_2	},	/*	*/
    {GPIOB, GPIO_PIN_0	},	/*	*/
    {GPIOA, GPIO_PIN_7	},	/*SPI1_MOSI	*/
    {GPIOA, GPIO_PIN_6	},	/*SPI1_MISO	*/
    {GPIOA, GPIO_PIN_5	},	/*SPI1_SCK	*/
    {GPIOA, GPIO_PIN_4	},	/*SPI1_NSS	SPI1_NSS (opt)*/
    {GPIOA, GPIO_PIN_3	},	/*	*/
    {GPIOA, GPIO_PIN_2	},	/*	*/
    {GPIOA, GPIO_PIN_1	},	/*	*/
    {GPIOA, GPIO_PIN_0	},	/*-WKUP	*/
    {GPIOC, GPIO_PIN_15	},	/*-OSC32_OUT	*/
    {GPIOC, GPIO_PIN_14	},	/*-OSC32_IN		*/
    {GPIOC, GPIO_PIN_13	},	/*-TAMPER-RTC	Output	GPIO_Output	*/
    {GPIOB, GPIO_PIN_7	},	/*I2C1_SDA	*/
    {GPIOB, GPIO_PIN_6	},	/*I2C1_SCL	*/
    {GPIOB, GPIO_PIN_5	},	/*	*/
    {GPIOB, GPIO_PIN_4	},	/*	*/
    {GPIOB, GPIO_PIN_3	},	/*	*/
    {GPIOA, GPIO_PIN_15	},	/*	*/
    {GPIOA, GPIO_PIN_14	},	/*SYS_JTCK-SWCLK	*/
    {GPIOA, GPIO_PIN_13	},	/*SYS_JTMS-SWDIO	*/
    {GPIOA, GPIO_PIN_12	},	/*	*/
    {GPIOA, GPIO_PIN_11	},	/*	*/
    {GPIOA, GPIO_PIN_10	},	/*USART1_RX	*/
    {GPIOA, GPIO_PIN_9	},	/*USART1_TX	*/
    {GPIOA, GPIO_PIN_8	},	/*	*/
    {GPIOB, GPIO_PIN_15	},	/*	*/
    {GPIOB, GPIO_PIN_14	},	/*	*/
    {GPIOB, GPIO_PIN_13	},	/*	*/
    {GPIOB, GPIO_PIN_12	},	/*	*/
    {GPIOB, GPIO_PIN_8	},	/*CAN_RX	*/
    {GPIOB, GPIO_PIN_1	}	/*Output	GPIO_Output	Blue_LED*/

	
} ;

#ifdef __cplusplus
}
#endif

/*
 * UART objects
 */
RingBuffer rx_buffer1;
RingBuffer tx_buffer1;


/*
	install bridge hooks to syscalls that will allow printf() to
	access one of the USARTS
*/

#ifdef __GNUC__
  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the EVAL_COM1 and Loop until the end of transmission */
  
  /* 
  	huart6 is defined in usart.h and instantiated in usart.c 
  	usart.h is defined in chip.h and the header is loaded through UARTClass.h
  */ 
  
  HAL_UART_Transmit(&huart3, (uint8_t *)&ch, 1, 0xFFFF); 

  return ch;
}

//UARTClass Serial(UART, UART_IRQn, ID_UART, &rx_buffer1, &tx_buffer1);
UARTClass Serial(&huart3, USART3_IRQn, 3, &rx_buffer1, &tx_buffer1);
void serialEvent() __attribute__((weak));
void serialEvent() { }

// IT handlers
void UART_Handler(void)
{
//  Serial.IrqHandler();
}

// ----------------------------------------------------------------------------
/*
 * USART objects
 */
#if 1
RingBuffer rx_buffer2;
//RingBuffer rx_buffer3;
//RingBuffer rx_buffer4;
RingBuffer tx_buffer2;
//RingBuffer tx_buffer3;
//RingBuffer tx_buffer4;

USARTClass Serial1(&huart1, USART1_IRQn, 1, &rx_buffer2, &tx_buffer2);
void serialEvent1() __attribute__((weak));
void serialEvent1() { }
//USARTClass Serial2(USART1, USART1_IRQn, ID_USART1, &rx_buffer3, &tx_buffer3);
//void serialEvent2() __attribute__((weak));
//void serialEvent2() { }
//USARTClass Serial3(USART3, USART3_IRQn, ID_USART3, &rx_buffer4, &tx_buffer4);
//void serialEvent3() __attribute__((weak));
//void serialEvent3() { }

// IT handlers
void USART0_Handler(void)
{
//  Serial1.IrqHandler();
}

//void USART1_Handler(void)
//{
//  Serial2.IrqHandler();
//}

//void USART3_Handler(void)
//{
//  Serial3.IrqHandler();
//}

// ----------------------------------------------------------------------------

void serialEventRun(void)
{
  if (Serial.available()) serialEvent();
  if (Serial1.available()) serialEvent1();
//  if (Serial2.available()) serialEvent2();
//  if (Serial3.available()) serialEvent3();
}
#endif
