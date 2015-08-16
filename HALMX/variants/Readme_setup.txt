How to setup CubeMX and the platforms.txt/board.txt files.

A few notes. The include chip.h is probably more akin to board.h. I moved this to the variants folder. This way I do not need i#ifdefs for the board type. Such is already handled through HAL configuration files. As it is I have about half a dozen STM32 boards. It looks like this may also work with the L0 and F0 demo boards I have.

To get the serial stream to work on my F103RB Nucleo I had to change the include paths in platform.txt to not hard code the F4 paths. So I added some keys in boards.txt to do this.

Setting up the new board with cube was surprisingly simple. I practice it was much easier to do than to write down.
Run STM32CubeMX and 
Choose the board selector tab from the CubeMX menu and click the options to set all IP to default. 
Set up the settings menu
Point the setup path to variants. Create the *.ioc project in the folder (This will become the Variant name)
Set the toolchain to SWSTM32
Make sure peripheral initi is set to pair the .c .h files

I had to first do a copy all used libraries to get the gcc folder to appear
Generate the project which should populate the variants folder You can open the folder from the completion menu. 
Delete any demo examples and rename the correct *.s file to *.S for safety I deleted the other ones.

Back in the pin map window change any port pin initializations. ( side note: I did not do this the first time and did not get the USART3 mapped to the morpho pins. I was able to regen the project, re- compile it and it ran without changing any code.)

check the setting s menu. Copy only necessary library files should be set. Re generate the project.

At this point the project tree should be in place in the variants folder.

Copy the STM32duino files from a working variant into the new variant. This will be chip.h and the variant.h variant.cpp files. 


Use a differencing editor like TextWrangler (Or BBEdit) to compare the working main.c in the working variant to the main.c in the new variant folder. Look for the calls to setup() and loop, these should be inside the user code comments. I did note that simple changes through CubeMX do retain the code inside the user code comments.

At this point the cloned variant is ready to edit variant.cpp. The only real change I had to make between the F401RE and the F103RB was to change usart6 to usart3 (and remember to check the alternate function pin mapping.) 

I also noticed an option in the mac version of STM32CubeMX which is not in the windows version. This is to generate a .csv file of all the pin references. Most likely users will only need to create a new STM to arduino pin table. This .csv could be most useful for such. 

There are also issues with some of the non portable options to the gpio, like the GPIO_SPEED_FAST verses GPIO_SPEED_HIGH. I also had to move the __io_putchar() from the uart class into the variant as I was hard calling the serial write code. In theory this should let printf() connect to the serial port, but it is not working for me at present. I have not tried this again. 

