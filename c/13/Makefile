CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -g

main: object.o list.o main.c
	$(CC) $(CFLAGS) main.c object.c list.c -o main

object: object.c
	$(CC) $(CFLAGS) object.c -o object.o

list: list.c
	$(CC) $(CFLAGS) list.c -o list.o

clean:
	rm -f *.o main

