CC = gcc
CCFLAGS = -Wall -g 

graph.o: graph.c graph.h
	$(CC) $(CCFLAGS) -c graph.c graph.h

queue.o: queue.c queue.h
	$(CC) $(CCFLAGS) -c queue.c queue.h

.PHONY : clean
clean:
	rm *.o