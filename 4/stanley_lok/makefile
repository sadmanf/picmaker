all: picmaker.o
	gcc -o picmaker picmaker.c

picmaker.o: picmaker.c
	gcc -c picmaker.c

clean:
	rm -rf *.ppm
	rm -rf *~
	rm -rf *.o
