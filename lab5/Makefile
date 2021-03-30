build: lab5

lab5: main.o queue.o stack.o
	gcc main.o queue.o stack.o -o lab5

main.o: main.c

queue.o: queue.h queue.c

stack.o: stack.h stack.c

run:
	./lab5

memcheck:
	valgrind ./lab5

make clean:
	rm -f *.o lab5

