:: This batch file renames the <startup_stm32f030x6.s> file extension in to capital letter
:: Use it in case you re-create the STM32CubeMX configuration files.  
:: 31 Mar 2016 by Vassilis Serasidis
::
SET var=%cd%
ren %var%\Drivers\CMSIS\Device\ST\STM32F1xx\Source\Templates\gcc\startup_stm32f103xb.s startup_stm32f103xb.S