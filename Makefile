CC=gcc
CFLAGS=-Wall -Wextra -O2

all: roleta

roleta: roleta.c
	$(CC) $(CFLAGS) roleta.c -o roleta

clean:
	rm -f roleta
