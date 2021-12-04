.PHONY: clean

link_list: link_list.o
			gcc -g -Wall link_list.o -o link_list

link_list.o: link_list.h link_list.c
			gcc -g -Wall -c link_list.c

clean:
		rm -r *.o link_list