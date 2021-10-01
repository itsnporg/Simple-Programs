# Author      : Prajwal Chapagain <prajjwal2058@gmail.com>
# Date        : Monday Aug 16, 2021 20:02:04 NPT
# License     : MIT

DEBUG=0

STD=-std=c99
WARN=-Wall -Wextra -Wpedantic \
     -Wformat=2 -Wshadow \
     -Wwrite-strings -Wstrict-prototypes -Wold-style-definition \
     -Wredundant-decls -Wnested-externs -Wmissing-include-dirs

OPTIMIZE=-O2
DEBUG_FLAGS=-g

CC=clang
CFLAGS=$(STD) -MMD

# GCC warnings that Clang doesn't provide:
ifeq ($(CC),gcc)
    WARN += -Wjump-misses-init -Wlogical-op
endif

ifeq ($(DEBUG), 1)
	CFLAGS += $(DEBUG_FLAGS) $(WARN) -DDEBUG
else
	CFLAGS += $(OPTIMIZE) -DNDEBUG
endif

BIN_DIR=./bin
BUILD_DIR=./build
INCLUDE_DIR=./include
SRC_DIR=./src

ifneq (,$(wildcard $(INCLUDE_DIR)))
    CFLAGS += -I$(INCLUDE_DIR)
endif

SRCS=$(wildcard $(SRC_DIR)/*.c)
OBJS=$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
DEPS=$(patsubst %.o, %.d, $(OBJS))

TARGET=reverse_reverser

LIBS=-lm

$(BIN_DIR)/$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

-include ($(DEPS))

.PHONY: clean
clean:
	$(RM) $(BIN_DIR)/* $(BUILD_DIR)/*



