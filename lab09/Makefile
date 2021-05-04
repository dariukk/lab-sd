CC = gcc
CFLAGS = -Wall -c -g

all: lab9

lab9: main.o dequeue.o list.o helpers.o graph.o
	gcc main.o dequeue.o list.o helpers.o graph.o -o lab9

graph.o: graph.c graph.h 

main.o: main.c dequeue.h graph.h

dequeue.o: dequeue.c list.h helpers.h dequeue.h

helpers.o: helpers.c helpers.h

list.o: list.c list.h

run:
	./lab9

memcheck:
	valgrind ./lab9

make clean:
	rm -f *.o lab9
