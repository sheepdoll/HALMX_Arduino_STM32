/*


*/

#ifndef _VARIANT_NUCLEO_F4xx_
#define _VARIANT_NUCLEO_F4xx_

#include <chip.h>
 /* #include "stm32f4xx_hal.h"  include this here so we do not have to use #ifdefs */

/** Master clock frequency */
#define VARIANT_MCK			F_CPU


#if 1
/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

//#include "Arduino.h"
#ifdef __cplusplus
#include "UARTClass.h"
#include "USARTClass.h"
#endif
#endif





#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

/**
 * Libc porting layers
 */
#if defined (  __GNUC__  ) /* GCC CS3 */
#    include <syscalls.h> /** RedHat Newlib minimal stub */
#endif

/*
	From Roger Clark's maple port.  Convenance alias to
	STM Nucleo abstractions.  If the LED is not blinking
	check this that this mapping is correct for the
	Device Under Test (DIT) These arrays must work
	together and are the main reason we have so many STM32
	Variants
 
 Pin aliases: these give the GPIO port/bit for each pin as an
 * enum. These are optional, but recommended. They make it easier to
 * write code using low-level GPIO functionality. 
 
*/
/* This mapping is for Nucleo Boards */
enum {
    PA3, PA2, PA10, PB3, PB5, PB4, PB10, PA8,
    PA9, PC7, PB6, PA7, PA6, PA5, PB9,PB8,
    PA0, PA1, PA4, PB0, PC1, PC0,
    PC10,PC12,PB7,PC13,PC14,PC15,PC2,PC3,PC11,PD2,PC9,PC8,PC6,PC5,PA12,PA11,PB12,PB11,
    PB2,PB1,PB15,PB14,PB13
};


/* Definitions and types for pins */

/* low level defines are declared in STM32CubeMX headers */

/* 
	This structure maps the high level settings of the port 
	See the HALMX core function variant and wiring_digital 
	to see how to use 
*/
typedef struct _Pin2PortMapArray
{
	/* 
		define the Abstract Hal port reference
		
		IMPORTANT NOTE: this definition is opaque and
		defined inside the chip family
		do not try and change the include name locally
		unless you know what you are doing
		
	*/	
  	GPIO_TypeDef *GPIOx_Port; 		/* defined in stm32f401xe.h */
  	/* 
  		we only record the pin here as the typedef record
  		is normally mutable and only used by the init code
  	*/
  	uint32_t 	Pin_abstraction;	/* must match type in GPIO_InitTypeDef struct */
  
  
} Pin2PortMapArray ;

/* Pins table to be instanciated into variant.cpp */
extern const Pin2PortMapArray g_Pin2PortMapArray[] ;

#ifdef __cplusplus
}
#endif



#if 1
/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus

extern UARTClass Serial;
extern USARTClass Serial1;
//extern USARTClass Serial2;
//extern USARTClass Serial3;

#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_MONITOR         Serial
#define SERIAL_PORT_USBVIRTUAL      SerialUSB
#define SERIAL_PORT_HARDWARE_OPEN   Serial1
#define SERIAL_PORT_HARDWARE_OPEN1  Serial2
#define SERIAL_PORT_HARDWARE_OPEN2  Serial3
#define SERIAL_PORT_HARDWARE        Serial
#define SERIAL_PORT_HARDWARE1       Serial1
#define SERIAL_PORT_HARDWARE2       Serial2
#define SERIAL_PORT_HARDWARE3       Serial3


#endif

#endif
