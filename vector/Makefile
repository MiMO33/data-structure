CC = gcc
CCFALGS = -Wall -g -std=c89

all: main.o vector.o 
	$(CC) $(CCFLAGS) vector.o main.o -o vector_test

main.o: main.c
	$(CC) -c $(CCFLAGS) main.c

vector.o: vector.h vector.c
	$(CC) -c $(CCFLAGS) vector.h vector.c

clean: 
	rm *.o vector_test