CC=gcc
CFLAGS=-I.

shortest_path: shortest_path.o 
	$(CC) -o shortest_path shortest_path.o

clean :
		rm shortest_path shortest_path.o

test: shortest_path
	bash test.sh

