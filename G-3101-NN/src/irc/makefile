CC=gcc
CCFLAGS = -Wall --pedantic -g
ADDLIB=ar
LIB=soundredes

all: clean server client


server: server.o
	@$(CC) $(CFLAGS) -o server server.o

server.o: server.c
	@$(CC) $(CFLAGS) -c server.c

client: client.o
	@$(CC) $(CFLAGS) -o client client.o

client.o: client.c
	@$(CC) $(CFLAGS) -c client.c


clean: clear

clear:
	@rm -f server server.o client client.o>/dev/null 2> /dev/null
