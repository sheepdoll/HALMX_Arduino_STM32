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



extern const Pin2PortMapArray g_Pin2PortMapArray[]=
{    
	
	{GPIOA, GPIO_PIN_0	},	/*  PF6		8	I/O				*/
	{GPIOA, GPIO_PIN_1	},	/*  PC3		9	I/O				*/
	{GPIOA, GPIO_PIN_2	},	/*  PA5		10	I/O				*/
	{GPIOA, GPIO_PIN_3	},	/*  PG2		11	I/O				*/
	{GPIOA, GPIO_PIN_4	},	/*  PG3		12	I/O				*/
	{GPIOA, GPIO_PIN_5	},	/*  PG13	13	Output	GPIO_Output	LD3 [Green Led]	*/
	{GPIOA, GPIO_PIN_6	},	/*  PC9		14	I/O	I2C3_SDA I2C3_SDA [ACP/RF_SDA]]	*/
	{GPIOA, GPIO_PIN_7	},	/*  PA8		15	I/O	I2C3_SCL I2C3_SCL [ACP/RF_SCL]]	*/
	{GPIOA, GPIO_PIN_9	},	/*  PC8		16	I/O				*/		
	{GPIOA, GPIO_PIN_10	},	/*  PC11	17	I/O				*/		
	{GPIOA, GPIO_PIN_13	},	/*  PD4		18	I/O				*/		
	{GPIOA, GPIO_PIN_14	},	/*  PD5		19	I/O				*/		
  
	{GPIOB, GPIO_PIN_1	},	/*  PD7		20	I/O				*/		

	{GPIOF, GPIO_PIN_0	},	/*  PG9		21	I/O				*/	
  {GPIOF, GPIO_PIN_1	},	/*  PG9		21	I/O				*/	
  
};

#ifdef __cplusplus
}
#endif

/*
 * UART objects
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
