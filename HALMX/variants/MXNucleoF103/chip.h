/* stub for hardware types */
#ifndef _CHIP_NUCLEO_F4xx_
#define _CHIP_NUCLEO_F4xx_

#include <stdbool.h>  /* for wiring constants */

#include "stm32f103xb.h"  /* Ideally this is defined in variant */
#include "usart.h"

/* define some abstractions that are identical to Arduino */

/* from STM boilerplate: 
			Systick timer is used by default as source of time base, but user 
            can eventually implement his proper time base source (a general purpose 
            timer for example or other time source), keeping in mind that Time base 
            duration should be kept 1ms since PPP_TIMEOUT_VALUEs are defined and 
            handled in milliseconds basis.
*/
/* returns System clock milliseconds HAL must be active */
#define  millis(a1) HAL_GetTick(a1) 

/* from STM boilerplate: 
			Care must be taken if HAL_Delay() is called from a 
             peripheral ISR process, the Tick interrupt line must have higher priority 
            (numerically lower) than the peripheral interrupt. Otherwise the caller 
            ISR process will be blocked. 
*/
/* delay in micoseconds  Uses HAL system clock */
#define delay(a2) HAL_Delay(a2)


#endif