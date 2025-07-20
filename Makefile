# Makefile
CC = gcc
CFLAGS = -Wall -Werror -I./src

SRC = src/ton.c test/main.c
OUT = build/ton_demo

all: $(OUT)

$(OUT): $(SRC)
	mkdir -p build
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf build

.PHONY: all clean
