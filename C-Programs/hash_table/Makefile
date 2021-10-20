BIN_DIR=./bin
OBJS_DIR=./obj
SRCS_DIR=./src

SRCS=$(wildcard $(SRCS_DIR)/*.c)
OBJS=$(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
DEPS=$(OBJS:$(OBJS_DIR)/%.o=%.d)

CC=cc
CFLAGS=-Wall -Wextra -MMD -MP -std=c11
CLFLAGS=-lm

BIN=$(BIN_DIR)/hashtable

$(BIN): $(OBJS)
	$(CC) $(CLFLAGS) $^ -o $@

-include $(DEPS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) $(BIN) $(OBJS_DIR)/*
