# Demo projekt: generira ELF i linkerovu map datoteku za analizu.
# Primjeri: make | make OPT=-O0 BUILD=build/O0 | make CC=arm-none-eabi-gcc
.RECIPEPREFIX = >

CC     ?= gcc
OPT    ?= -Os
BUILD  ?= build
CFLAGS  = $(OPT) -Wall -Wextra -ffunction-sections -fdata-sections
LDFLAGS = -Wl,--gc-sections -Wl,-Map=$(BUILD)/demo.map
SRC     = main.c uart.c config.c sensor.c
OBJ     = $(SRC:%.c=$(BUILD)/%.o)

all: $(BUILD)/demo.elf

$(BUILD)/demo.elf: $(OBJ)
> $(CC) $(OBJ) $(LDFLAGS) -o $@

$(BUILD)/%.o: %.c | $(BUILD)
> $(CC) $(CFLAGS) -c $< -o $@

$(BUILD):
> mkdir -p $(BUILD)

clean:
> rm -rf build

.PHONY: all clean
