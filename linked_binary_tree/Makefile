.PHONY: clean

main: main.o
	gcc -O0 -g -Wall main.o -o main

main.o: main.h main.c
	gcc -O0 -g -Wall -c main.c

clean:
	rm -r *.o main