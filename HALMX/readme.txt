/*

	Sandbox for using CubeMX CMSIS and HAL with eclipse files
	note that there is a poison pill in the *.ld that may keep this from
	a distributable source licence.  Check all licence files in headers
	before including this in other distributions. All other licences are inherited
	from the source file tree.

	Improvements derivations (c) 2015 Julie S. Porter (sheepdoll) This code is
	for educational use only.  It is not warranted to be of any use or even to work.
	
	
	This header must accompany any and all distributions.

*/


Revision History:
15 June 2015
	Added definition for F103RB Nucleo board.  Changes to platforms.txt
	to support different processor cores from boards.txt
14 June 2015
	Serial write enabled from USART6 remapped to pins 12 and 14
	
13 June 2015:
	partial implementation of digitalIO in wiring.  Mapping of some millisecond
	timer abstractions to wiring.h
	start of serial stream imports
10 June 2015:  
	initial setup.  Import project from STM32CubeMX.  Change platforms.txt and boards.txt
	 to compile from CSMIS and HAL.  
	 Changed some compiler defines to reflect HAL options.
	 Moved and renamed startup_stm32f401xe.S so that Arduino can find it.