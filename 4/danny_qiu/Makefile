FLAGS=-Wall -Wno-unused-variable -Wno-unused-function
LIBS=-lm
FILES=generator.c
OUTPUT_FILE := output_$(shell ls output_*.ppm 2>/dev/null | wc -l | xargs).ppm

all: generate

generate: generator.c generator.h
	@gcc $(FLAGS) -o generator $(LIBS) generator.c
	./generator 511 $(OUTPUT_FILE)
	display $(OUTPUT_FILE)

clean:
	rm -f output_*.ppm
