CC = gcc
CFLAGS = -std=c99

build:
	$(CC) $(CFLAGS) -o tabler tabler.c

install:
	cp tabler /usr/bin/tabler

clean:
	rm tabler
