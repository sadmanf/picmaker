FLAGS=-Wall -Wno-unused-variable -Wno-unused-function

all: picmaker.o
	@gcc $(FLAGS) picmaker.o -o picmaker
	@make clean
	@./picmaker
	@display image.ppm

picmaker.o: picmaker.c
	@gcc -c picmaker.c

clean:
	@rm -f *.o
