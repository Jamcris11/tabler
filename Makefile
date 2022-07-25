CC = gcc

build:
	$(CC) -o tabler tabler.c

install:
	cp tabler /usr/bin/tabler

clean:
	rm tabler
