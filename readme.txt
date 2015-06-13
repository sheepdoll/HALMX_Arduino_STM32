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

10 June 2015:  
	initial setup.  Import project from STM32CubeMX.  Change platforms.txt and boards.txt
	 to compile from CSMIS and HAL.  
	 Changed some compiler defines to reflect HAL options.
	 Moved and renamed startup_stm32f401xe.S so that Arduino can find it.