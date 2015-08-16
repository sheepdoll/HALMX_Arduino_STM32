/*

	Sandbox for using CubeMX CMSIS and HAL with eclipse files
	note that there is a poison pill in the *.ld that may keep this from
	a distributable source license.  Check all license files in headers
	before including this in other distributions. All other licenses are inherited
	from the source file tree.

	Improvements derivations (c) 2015 Julie S. Porter (sheepdoll) This code is
	for educational use only.  It is not warranted to be of any use or even to work.
	
	
	This header must accompany any and all distributions.
*/

/*
	Background philosophy.

	HALMX is a variation of Arduino_STM32.  The focus is to allow for the STM32CubeMX
	tool to automatically configure IO on STM32 devices.  This is a fork of the Maple
 	library project maintained under Arduino_STM32.  It differs in that all low level
 	calls are handled by HAL rather than the maple Libs.

	The Arduino Core is kept closer to the public distribution currently on Arduino.cc
	This way any STM core can be quickly evaluated with only changes to the
	variant.cpp file and pin mapping tables.

	For more information setting up STM32CubeMx and creating new ST platform variants
 	see Readme_setup.txt and CubeMX_installation.txt.

	The philosophy of this distribution is to float the Arduino libraries on top of
	The Hardware Abstraction Layer (HAL)  Configuration is done through the CubeMX
	Tool.  

	It is possible to bypass the Arduino Core directly and call the HAL abstractions
	From inside the sketch. See the HAL_Direct exampled for how this is done.

	One major difference is that configuration normally done in setup() are handled
	inside of main.c These are set by the CubeMX tool.  This way serial baud rates are
	not directly settable in the sketch. The call to the serialx.begin constructor is
	still required to connect the HAL structures to the Arduino Core stream 
	structures. This is done before setup() is called. 

	See the section /* USER CODE BEGIN 2 */ inside main.c to see how initVariant() 
	and setup() are called. Each platform has it's own main.c inside the 
	variant/Src folder.

	loop() is called from /* USER CODE BEGIN 3 */ along with an optional
	serialEventRun() callback.  

	By retaining the main.c installed by CubeMX and including callbacks inside
	the user code comments, CubeMX can be run to change configurations without
	the need to write additional code that would normally appear inside
	the setup() callback.   

	This is a work in progress with only serial stream through the STlink backchannel
	and digital write partly tested.  

	Areas that currently need work are:
	Timer interrups for microsecond delays.
	USB support on devices that have onboard USB hardware
	Digital and analog inputs. 
	SPI/I2C and CAN bus (currently configured through CubeMX/HAL setup)

	It should also be possible to access the ILI9341 through the TFT controller
	on the F429I Discovery kit, Using the existing HAL examples. 


*/


Revision History:
15-16 August 2015
	Configured Discovery variants for F0 and F429I
	Added blink and serial examples used to test compiler
	Added documentation for OS X installation of STM32CubeMx under OS X
	Added script to launch STM32CubeMx app from terminal.

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