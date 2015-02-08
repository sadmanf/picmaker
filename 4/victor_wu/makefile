all: pic.o
	gcc -o Gen pic.o

pic.o: pic.c
	gcc -c pic.c

clean:
	rm pic.o
	rm image.ppm
	rm Gen
