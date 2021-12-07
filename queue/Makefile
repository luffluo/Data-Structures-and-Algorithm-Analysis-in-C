.PHONY: clean

main: main.o
	gcc -g -Wall main.o -o main

main.o: head.h main.c
	gcc -g -Wall -c main.c

clean:
	rm -r *.o main