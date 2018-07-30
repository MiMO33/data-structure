CC = gcc
CCFALGS = -Wall -g -std=c89

all: main.o vector.o bubble_sort.o
	$(CC) $(CCFLAGS) bubble_sort.o vector.o main.o -o vector_test.out

main.o: main.c vector/vector.h
	$(CC) -c $(CCFLAGS) main.c

vector.o: sort/bubble_sort.h vector/vector.h vector/vector.c
	$(CC) -c $(CCFLAGS) vector/vector.c

bubble_sort.o: sort/bubble_sort.c sort/bubble_sort.h
	$(CC) -c $(CCFLAGS) sort/bubble_sort.c

clean: 
	rm *.o 