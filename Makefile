CC = gcc
CFLAGS = -g -O2

.SUFFIXES: .out .c

.c.out:
	$(CC) $(CFLAGS) $< -o $@

IN = $(wildcard *.c)
OUT = $(IN:.c=.out)

all: $(OUT)
