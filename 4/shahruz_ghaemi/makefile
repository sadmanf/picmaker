all: picmaker.o
	gcc -o picmaker picmaker.o
	make run
	make clean

picmaker.o: picmaker.c
	gcc -c picmaker.c

run:
	./picmaker
	convert pic.ppm pic.jpg

clean:
	rm *.o
	rm picmaker
	rm pic.ppm
