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


/*
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
 #if 0
     /* Arduino-like header, right connectors */
    {GPIOA, NULL,   ADC1,   3,  0,    3}, /*  D0/PA3	USART_RX	*/
    {GPIOA, NULL,   ADC1,   2,  0,    2}, /*  D1/PA2	USART_TX	*/

    {GPIOA, TIMER1, NULL,  10,  3, ADCx}, /*  D2/PA10	USART1_RX	*/
    {GPIOB, TIMER2, NULL,   3,  2, ADCx}, /*  D3/PB3	SWO			*/
    {GPIOB, TIMER3, NULL,   5,  2, ADCx}, /*  D4/PB5	GPIO T3		*/
    {GPIOB, TIMER3, NULL,   4,  1, ADCx}, /*  D5/PB4  	GPIO T3		*/
    {GPIOB, TIMER2, NULL,  10,  3, ADCx}, /*  D6/PB10	I2C2_SCL	*/
    {GPIOA, TIMER1, NULL,   8,  1, ADCx}, /*  D7/PA8	GPIO T1		*/
                   
    {GPIOA, TIMER1, NULL,   9,  2, ADCx}, /*  D8/PA9	USART1_TX	*/
    {GPIOC, NULL,   NULL,   7,  0, ADCx}, /*  D9/PC7	GPIO		*/
    {GPIOB, TIMER4, NULL,   6,  1, ADCx}, /*  D10/PB6	I2C1_SCL	*/
    {GPIOA, NULL,   ADC1,   7,  0,    7}, /*  D11/PA7	SPI_MOSI_NC	*/
    {GPIOA, NULL,   ADC1,   6,  0, 	  6}, /*  D12/PA6	SPI_MISO_NC */
    {GPIOA, NULL,   NULL,   5,  0, ADCx}, /*  D13/PA5 	LED - no ADC12_IN5 SPI_SCK !*/
    {GPIOB, TIMER4, NULL,   9,  4, ADCx}, /*  D14/PB9 	I2C1_SDA	*/
    {GPIOB, TIMER4, NULL,   8,  3, ADCx}, /*  D15/PB8 	I2C1_SCL	*/
                   
    {GPIOA, NULL,   ADC1,   0,  0,    0}, /*  D16/A0/PA0 GPIO		*/
    {GPIOA, NULL,   ADC1,   1,  0,    1}, /*  D17/A1/PA1 GPIO		*/
    {GPIOA, NULL,   ADC1,   4,  0,    4}, /*  D18/A2/PA4 SPI_NSS	*/
    {GPIOB, TIMER3, ADC1,   0,  3,    8}, /*  D19/A3/PB0 GPIO		*/
    {GPIOC, NULL,   ADC1,   1,  0,   11}, /*  D20/A4/PC1 GPIO		*/
    {GPIOC, NULL,   ADC1,   0,  0,   10}, /*  D21/A5/PC0 GPIO		*/

#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Pins descriptions
 */
/* pPort	ulPin	ulPeripheralId	ulPinType	ulPinConfiguration	ulPinAttribute	ulAnalogChannel	ulADCChannelNumber ulPWMChannel ulTCChannel */

extern const PinDescription g_APinDescription[]=
{    
	{ GPIOA,  GPIO_PIN_2|GPIO_PIN_3,  GPIO_MODE_AF_PP, GPIO_NOPULL, GPIO_SPEED_LOW, GPIO_AF7_USART2}, /*  D0/PA3	USART_RX	*/
	{ GPIOA,  GPIO_PIN_2|GPIO_PIN_3,  GPIO_MODE_AF_PP, GPIO_NOPULL, GPIO_SPEED_LOW, GPIO_AF7_USART2}, /*  D1/PA2	USART_TX	*/
	
    {GPIOA, GPIO_PIN_10,	GPIO_MODE_OUTPUT_PP, GPIO_NOPULL,  GPIO_SPEED_LOW, 0}, /*  D2/PA10	USART1_RX	*/
    {GPIOB, GPIO_PIN_3,		GPIO_MODE_OUTPUT_PP, GPIO_NOPULL,  GPIO_SPEED_LOW, 0}, /*  D3/PB3	SWO			*/
    {GPIOB, GPIO_PIN_5,		GPIO_MODE_OUTPUT_PP, GPIO_NOPULL,  GPIO_SPEED_LOW, 0}, /*  D4/PB5	GPIO T3		*/
    {GPIOB, GPIO_PIN_4,		GPIO_MODE_OUTPUT_PP, GPIO_NOPULL,  GPIO_SPEED_LOW, 0}, /*  D5/PB4  	GPIO T3		*/
    {GPIOB, GPIO_PIN_10,	GPIO_MODE_OUTPUT_PP, GPIO_NOPULL,  GPIO_SPEED_LOW, 0}, /*  D6/PB10	I2C2_SCL	*/
    {GPIOA, GPIO_PIN_8,		GPIO_MODE_OUTPUT_PP, GPIO_NOPULL,  GPIO_SPEED_LOW, 0}, /*  D7/PA8	GPIO T1		*/

    {GPIOA, GPIO_PIN_9,		GPIO_MODE_OUTPUT_PP, GPIO_NOPULL,  GPIO_SPEED_LOW, 0}, /*  D8/PA9	USART1_TX	*/
    {GPIOC, GPIO_PIN_7, 	GPIO_MODE_OUTPUT_PP, GPIO_NOPULL,  GPIO_SPEED_LOW, 0}, /*  D9/PC7	GPIO		*/
    {GPIOB, GPIO_PIN_6,		GPIO_MODE_OUTPUT_PP, GPIO_NOPULL,  GPIO_SPEED_LOW, 0}, /*  D10/PB6	I2C1_SCL	*/
    {GPIOA, GPIO_PIN_7,		GPIO_MODE_OUTPUT_PP, GPIO_NOPULL,  GPIO_SPEED_LOW, 0}, /*  D11/PA7	SPI_MOSI_NC	*/
    {GPIOA, GPIO_PIN_6,		GPIO_MODE_OUTPUT_PP, GPIO_NOPULL,  GPIO_SPEED_LOW, 0}, /*  D12/PA6	SPI_MISO_NC */
    
    {GPIOA, GPIO_PIN_5,		GPIO_MODE_OUTPUT_PP, GPIO_PULLUP,  GPIO_SPEED_FAST, 0}, /*  D13/PA5 	LED - no ADC12_IN5 SPI_SCK !*/
    
    {GPIOB, GPIO_PIN_9,		GPIO_MODE_OUTPUT_PP, GPIO_NOPULL,  GPIO_SPEED_LOW, 0}, /*  D14/PB9 	I2C1_SDA	*/
    {GPIOB, GPIO_PIN_8,		GPIO_MODE_OUTPUT_PP, GPIO_NOPULL,  GPIO_SPEED_LOW, 0}, /*  D15/PB8 	I2C1_SCL	*/

    {GPIOA, GPIO_PIN_0,		GPIO_MODE_OUTPUT_PP, GPIO_NOPULL,  GPIO_SPEED_LOW, 0}, /*  D16/A0/PA0 GPIO		*/
    {GPIOA, GPIO_PIN_1,		GPIO_MODE_OUTPUT_PP, GPIO_NOPULL,  GPIO_SPEED_LOW, 0}, /*  D17/A1/PA1 GPIO		*/
    {GPIOA, GPIO_PIN_4,		GPIO_MODE_OUTPUT_PP, GPIO_NOPULL,  GPIO_SPEED_LOW, 0}, /*  D18/A2/PA4 SPI_NSS	*/
    {GPIOB, GPIO_PIN_0,		GPIO_MODE_OUTPUT_PP, GPIO_NOPULL,  GPIO_SPEED_LOW, 0}, /*  D19/A3/PB0 GPIO		*/
    {GPIOC, GPIO_PIN_1,		GPIO_MODE_OUTPUT_PP, GPIO_NOPULL,  GPIO_SPEED_LOW, 0}, /*  D20/A4/PC1 GPIO		*/
    {GPIOC, GPIO_PIN_0,		GPIO_MODE_OUTPUT_PP, GPIO_NOPULL,  GPIO_SPEED_LOW, 0}  /*  D21/A5/PC0 GPIO		*/

    /*
    	 these signals are only on the Morpho headers
    	 Odd pins are on the left header
    	 Even pins are on the right header                 
    */
 #if 0
    
    {GPIOC, NULL,   NULL,  10,  0, ADCx}, /*  D22/PC10 	SPI_SCK			ML1 */
	{GPIOC, NULL,   NULL,  12,  0, ADCx}, /*  D23/PC12	SPI_MOSI		ML3 */
    {GPIOB, TIMER4, NULL,   7,  2, ADCx}, /*  D24/PB7	I2C1_SDA		M21 */
    {GPIOC, NULL,   NULL,  13,  0, ADCx}, /*  D25/PC13 USER BLUE BUTTON M23 */
    {GPIOC, NULL,   NULL,  14,  0, ADCx}, /*  D26/PC14 RCC_OSC32_IN 	M25 */
    {GPIOC, NULL,   NULL,  15,  0, ADCx}, /*  D27/PC15 RCC_OSC32_OUT	M26 */
    {GPIOC, NULL,   ADC1,   2,  0,   12}, /*  D28/PC2	SPI2_MISO		M35 */
    {GPIOC, NULL,   ADC1,   3,  0,   13}, /*  D29/PC3	GPIO			M37 */
    {GPIOC, NULL,   NULL,  11,  0, ADCx}, /*  D30/PC11	SPI3_MISO		ML2 */
    {GPIOD, NULL,   NULL,   2,  0, ADCx}, /*  D31/PD2 	GPIO			ML4 */
    {GPIOC, NULL,   NULL,   9,  0, ADCx}, /*  D32/PC9	GPIO			MR1 */
    {GPIOC, NULL,   NULL,   8,  0, ADCx}, /*  D33/PC8	GPIO			MR2 */
    {GPIOC, NULL,   NULL,   6,  0, ADCx}, /*  D34/PC6	GPIO			MR4 */
    {GPIOC, NULL,   ADC1,   5,  0,   15}, /*  D35/PC5	GPIO			MR6 */
    {GPIOA, NULL,   NULL,  12,  0, ADCx}, /*  D36/PA12 USART6_RX USB_DP M12*/
    {GPIOA, TIMER1, NULL,  11,  4, ADCx}, /*  D37/PA11 USART6_TX USB_DM M14 */
    {GPIOB, NULL,   NULL,  12,  0, ADCx}, /*  D38/PB12	SPI2_NSS		M16 */
    {GPIOB, TIMER2, NULL,  11,  4, ADCx}, /*  D39/PB11	I2C2_SDA		M18 PWM-not working?*/
    {GPIOB, NULL,   NULL,  2,   0, ADCx}, /*  D40/PB2	BOOT1 !!		ML7 */
    {GPIOB, TIMER3, ADC1,   1,  4,    9}, /*  D41/PB1	GPIO 			M24 */
    {GPIOB, NULL,   NULL,  15,  0, ADCx}, /*  D42/PB15	SPI2_MOSI		M26 */
    {GPIOB, NULL,   NULL,  14,  0, ADCx}, /*  D43/PB14	SPI2_MISO		M28 */
    {GPIOB, NULL,   NULL,  13,  0, ADCx}, /*  D44/PB13	SPI2_SCK		M30 */
    {GPIOC, NULL,   ADC1,   4,  0,   14}  /*  D45/PC4	GPIO			M34 */
 #endif 
  	// JTAG Single wire pins
	// {GPIOA, NULL,   NULL, 13, 0, ADCx},/* D41/PA13 	TMS	do not use	M13 */
	// {GPIOA, NULL,   NULL, 14, 0, ADCx},/* D42/PA14	TCK do not use	M15 */

// sheepdoll -- not sure why this one is locked out?
	// {GPIOA, TIMER2, NULL, 15, 1, ADCx},/* D43/PA15 	TDI do not use	M17 */
	
	
} ;

#ifdef __cplusplus
}
#endif


