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
  
  - 08 April 2016 Modified by Vassilis Serasidis
    This file is converted for using it with ST HAL + Arduino SAM core files.
*/

#include "arduino.h"
//#include "variant.h"


#ifdef __cplusplus
extern "C" {
#endif


/* Quick and dirty table based on Blue pill board schematic */
extern const Pin2PortMapArray g_Pin2PortMapArray[]=
{    

    {GPIOA, GPIO_PIN_0	},	/*-WKUP	*/
    {GPIOA, GPIO_PIN_1	},	/*	*/
    {GPIOA, GPIO_PIN_2	},	/*	*/
    {GPIOA, GPIO_PIN_3	},	/*	*/
    {GPIOA, GPIO_PIN_4	},	/*SPI1_NSS	SPI1_NSS (opt)*/
    {GPIOA, GPIO_PIN_5	},	/*SPI1_SCK	*/
    {GPIOA, GPIO_PIN_6	},	/*SPI1_MISO	*/
    {GPIOA, GPIO_PIN_7	},	/*SPI1_MOSI	*/
    {GPIOA, GPIO_PIN_8	},	/*	*/
    {GPIOA, GPIO_PIN_9	},	/*USART1_TX	*/
    {GPIOA, GPIO_PIN_10	},	/*USART1_RX	*/
    {GPIOA, GPIO_PIN_11	},	/*	*/
    {GPIOA, GPIO_PIN_12	},	/*	*/
    {GPIOA, GPIO_PIN_13	},	/*SYS_JTMS-SWDIO	*/
    {GPIOA, GPIO_PIN_14	},	/*SYS_JTCK-SWCLK	*/
    {GPIOA, GPIO_PIN_15	},	/*	*/
    
    {GPIOB, GPIO_PIN_0	},	/*	*/
    {GPIOB, GPIO_PIN_1	},	/*Output	GPIO_Output	Blue_LED*/
    {GPIOB, GPIO_PIN_2	},	/* BOOT1 */
    {GPIOB, GPIO_PIN_3	},	/*	*/
    {GPIOB, GPIO_PIN_4	},	/*	*/
    {GPIOB, GPIO_PIN_5	},	/*	*/
    {GPIOB, GPIO_PIN_6	},	/*I2C1_SCL	*/
    {GPIOB, GPIO_PIN_7	},	/*I2C1_SDA	*/
    {GPIOB, GPIO_PIN_8	},	/*CAN_RX	*/
    {GPIOB, GPIO_PIN_9	},	/*CAN_TX	*/
    {GPIOB, GPIO_PIN_10	},	/* USART3_TX	*/
    {GPIOB, GPIO_PIN_11	},	/* USART3_RX	*/
    {GPIOB, GPIO_PIN_12	},	/*	*/
    {GPIOB, GPIO_PIN_13	},	/* SPI2 SCK */
    {GPIOB, GPIO_PIN_14	},	/* SPI2 MISO */
    {GPIOB, GPIO_PIN_15	},	/* SPI2 MOSI */
    
    {GPIOC, GPIO_PIN_13	},	/*-TAMPER-RTC	Output	GPIO_Output	*/
    {GPIOC, GPIO_PIN_14	}, 	/*-OSC32_IN		*/
    {GPIOC, GPIO_PIN_15	} 	/*-OSC32_OUT	*/
} ;

#ifdef __cplusplus
}
#endif

#ifdef __GNUC__
  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */


// ----------------------------------------------------------------------------
/*
 * USART objects
 */

#ifdef USE_USART1
RingBuffer rx_buffer1;
RingBuffer tx_buffer1;
UARTClass Serial1(&huart1, USART1_IRQn, 0, &rx_buffer1, &tx_buffer1, USART1);
void Tx1_Handler(void){
  Serial1.TxHandler();
}
void Rx1_Handler(void){
  Serial1.RxHandler();
}
#endif

#ifdef USE_USART2
RingBuffer rx_buffer2;
RingBuffer tx_buffer2;
UARTClass Serial2(&huart2, USART2_IRQn, 1, &rx_buffer2, &tx_buffer2, USART2);
void Tx2_Handler(void){
  Serial2.TxHandler();
}
void Rx2_Handler(void){
  Serial2.RxHandler();
}
#endif

#ifdef USE_USART3
RingBuffer rx_buffer3;
RingBuffer tx_buffer3;
UARTClass Serial3(&huart3, USART3_IRQn, 2, &rx_buffer3, &tx_buffer3, USART3);
void Tx3_Handler(void){
  Serial3.TxHandler();
}
void Rx3_Handler(void){
  Serial3.RxHandler();
}
#endif
