all: a.out

a.out: drawing.o main.o
	g++ $^ -o $@

main.o: main.cpp drawing.h
	g++ main.cpp -c
	
drawing.o: drawing.cpp drawing.h
	g++ drawing.cpp -c


run: all
	./a.out

clean:
	rm a.out *.o out.ppm
