CC = gcc
CFLAGS = -g -Wall -ansi

all: arraylist.o main.o
	$(CC) $(CFLAGS)  -o arraylist arraylist.o  main.o
arraylist.o: arraylist.c arraylist.h
	$(CC) $(CFLAGS) -c arraylist.c

main.o: main.c
	$(CC) -I$(INCLUDE) $(CFLAGS) -c main.c