CC=gcc
CFLAGS = -Wall -g -std=c99 -D_XOPEN_SOURCE=700

all: server cliente

server: server.c
	$(CC) server.c -lm $(CFLAGS) -o server

cliente: cliente.c
	$(CC) cliente.c $(CFLAGS) -o cliente

clean:
	rm server cliente