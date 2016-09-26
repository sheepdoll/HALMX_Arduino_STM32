######################################
# Makefile by CubeMX2Makefile.py
######################################

######################################
# target
######################################
TARGET = MXNucleoF401

######################################
# building variables
######################################
# debug build?
DEBUG = 1
# optimization
OPT = -Os

#######################################
# pathes
#######################################
# source path
# Build path
BUILD_DIR = build

######################################
# source
######################################
C_SOURCES = \
  Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.c \
  Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c \
  Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc.c \
  Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc_ex.c \
  Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c \
  Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c \
  Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c \
  Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c \
  Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c \
  Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c \
  Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c \
  Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c \
  Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c \
  Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c \
  Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c \
  Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.c \
  Src/adc.c \
  Src/gpio.c \
  Src/main.c \
  Src/stm32f4xx_hal_msp.c \
  Src/stm32f4xx_it.c \
  Src/usart.c \
  ../../cores/mapleMX/itoa.c \
  ../../cores/mapleMX/syscalls.c \
  ../../cores/mapleMX/wiring_digital.c \
  ../../cores/mapleMX/wiring_shift.c \
  ../../cores/mapleMX/wiring.c \
  ../../cores/mapleMX/avr/dtostrf.c

CPP_SOURCES = \
  ../../cores/mapleMX/new.cpp \
  ../../cores/mapleMX/Print.cpp \
  ../../cores/mapleMX/RingBuffer.cpp \
  ../../cores/mapleMX/UARTClass.cpp \
  ../../cores/mapleMX/USARTClass.cpp \
  ../../cores/mapleMX/WMath.cpp \
  ../../cores/mapleMX/WString.cpp \
  ./variant.cpp \
  ./sketch.cpp
  
ASM_SOURCES = \
  Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates/gcc/startup_stm32f401xe.s

#######################################
# binaries
#######################################
CPP = arm-none-eabi-g++
CC = arm-none-eabi-gcc
AS = arm-none-eabi-gcc  -c -g -x assembler-with-cpp
CP = arm-none-eabi-objcopy
AR = arm-none-eabi-ar
SZ = arm-none-eabi-size
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S
 
#######################################
# CFLAGS
#######################################
# macros for gcc
AS_DEFS =
C_DEFS = -DUSE_HAL_DRIVER -DSTM32F401xE -DSTM32_MEDIUM_DENSITY  -DBOARD_NUCLEO_F401RE -D__STM32F4__ -DF_CPU=84000000L
# includes for gcc
AS_INCLUDES =
C_INCLUDES = -IInc
C_INCLUDES += -IInc
C_INCLUDES += -IDrivers/STM32F4xx_HAL_Driver/Inc
C_INCLUDES += -IDrivers/STM32F4xx_HAL_Driver/Inc/Legacy
C_INCLUDES += -IDrivers/CMSIS/Include
C_INCLUDES += -IInc
C_INCLUDES += -IDrivers/CMSIS/Device/ST/STM32F4xx/Include
C_INCLUDES += -IMiddlewares/ST/STM32_USB_Device_Library/Core/Inc
C_INCLUDES += -IMiddlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc
C_INCLUDES += -IInc
C_INCLUDES += -IInc
C_INCLUDES += -IDrivers/STM32F4xx_HAL_Driver/Inc
C_INCLUDES += -IDrivers/STM32F4xx_HAL_Driver/Inc/Legacy
C_INCLUDES += -IDrivers/CMSIS/Include
C_INCLUDES += -IInc
C_INCLUDES += -IDrivers/CMSIS/Device/ST/STM32F4xx/Include
C_INCLUDES += -IMiddlewares/ST/STM32_USB_Device_Library/Core/Inc
C_INCLUDES += -IMiddlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc
C_INCLUDES += -I./
C_INCLUDES += -I../../cores/mapleMX
C_INCLUDES += -I../../cores/mapleMX/avr
C_INCLUDES += -I../../cores/mapleMX/usb


# compile gcc flags
ASFLAGS =  -MMD -mcpu=cortex-m4 -DF_CPU=84000000L -DARDUINO=10604 -DARDUINO_STM_NUCLEO_F401RE -DARDUINO_ARCH_HALMX -DSTM32F401xE -DSTM32_MEDIUM_DENSITY -DSTM32F2 -DBOARD_NUCLEO_F401RE -mthumb -D__STM32F4__
ASFLAGS += $(AS_INCLUDES) -fdata-sections -ffunction-sections
#-mthumb -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp $(AS_DEFS) $(AS_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections
CFLAGS = -g -Os -w -DDEBUG_LEVEL=DEBUG_NONE -MMD -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500
CFLAGS += -DBOARD_MXNucleoF401 -mcpu=cortex-m4 -DF_CPU=84000000L -DARDUINO=10604 -DARDUINO_STM_NUCLEO_F401RE
CFLAGS += -DARDUINO_ARCH_HALMX -DSTM32F401xE -DSTM32_MEDIUM_DENSITY -DSTM32F2 -DBOARD_NUCLEO_F401RE -mthumb -D__STM32F4__ $(C_INCLUDES)
# -mthumb -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections
ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2
endif
# Generate dependency information
#CFLAGS += -MD -MP -MF .dep/$(@F).d
CPPFLAGS = -g -Os -w -DDEBUG_LEVEL=DEBUG_NONE -MMD -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500
CPPFLAGS += -fno-rtti -fno-exceptions -DBOARD_MXNucleoF401 -mcpu=cortex-m4 -DF_CPU=84000000L -DARDUINO=10604 -DARDUINO_STM_NUCLEO_F401RE
CPPFLAGS += -DARDUINO_ARCH_HALMX -DSTM32F401xE -DSTM32_MEDIUM_DENSITY -DSTM32F2 -DBOARD_NUCLEO_F401RE -mthumb -D__STM32F4__ $(C_INCLUDES)

#######################################
# LDFLAGS
#######################################
# link script
LDSCRIPT = STM32F401RETx_FLASH.ld
# libraries
LIBS = -lc -lm -lnosys
LIBDIR =
LDFLAGS = -Os -Wl,--gc-sections -mcpu=cortex-m4 -T$(LDSCRIPT) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,-L/Users/Arethusa/Documents/Arduino/hardware/HALMX_Arduino_STM32/HALMX/variants/MXNucleoF401/ld 
LDFLAGS += -lm -lgcc -mthumb -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--unresolved-symbols=report-all -Wl,--warn-common -Wl,--warn-section-align -Wl,--warn-unresolved-symbols 

#-mthumb -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -specs=nano.specs -T$(LDSCRIPT) $(LIBDIR) $(LIBS) -Wl,\
#-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections

# default action: build all
all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin

#######################################
# build the application
#######################################
# list of objects
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))
#
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(CPP_SOURCES:.cpp=.o)))
vpath %.cpp $(sort $(dir $(CPP_SOURCES)))
# list of ASM program objects
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.s=.o)))
vpath %.s $(sort $(dir $(ASM_SOURCES)))

$(BUILD_DIR)/%.o: %.cpp Makefile | $(BUILD_DIR) 
	$(CPP) -c $(CPPFLAGS)  -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.cpp=.lst)) $< -o $@

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR) 
	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(BUILD_DIR)/%.o: %.s Makefile | $(BUILD_DIR)
	$(AS) -c $(ASFLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) Makefile
	$(CPP) $(OBJECTS) $(LDFLAGS) -o $@
	$(SZ) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(HEX) $< $@
	
$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(BIN) $< $@	
	
$(BUILD_DIR):
	mkdir -p $@		

#######################################
# clean up
#######################################
clean:
	-rm -fR .dep $(BUILD_DIR)
  
#######################################
# dependencies
#######################################
-include $(shell mkdir .dep 2>/dev/null) $(wildcard .dep/*)

# *** EOF ***
