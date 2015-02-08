#include "generator.h"

char *output_file = "output.ppm";
const char *header = "P3";
int size = 500;
const int color_range = 255;

int r;
int g;
int b;

int main(int argc, char **argv) {
    if (argc == 2) {
        size = atoi(argv[1]);
    }
    else if (argc == 3) {
        size = atoi(argv[1]);
        output_file = argv[2];
    }
    else if (argc > 3) {
        printf("Usage: ./generator [size] [output_file]\n");
        return 1;
    }
    FILE *output = fopen(output_file, "w");
    fprintf(output, "%s\n", header);
    fprintf(output, "%d %d\n", size, size);
    fprintf(output, "%d\n", color_range);
    char line[100];
    int i;
    int j;
    for (i=0; i<size; ++i) {
        for (j=0; j<size; ++j) {
            r = (((color_range - i) * (color_range - i) & (color_range - j) * (color_range - j)) >> 8) - 10;
            g = (((color_range - i) * (color_range - i) ^ (color_range - j) * (color_range - j)) >> 8) - 10;
            b = (((color_range - i) * (color_range - i) * (color_range - j) * (color_range - j)) >> 8) - 10;
            sprintf(line, "%d %d %d ", validate(r), validate(g), validate(b));
            fwrite(line, strlen(line), 1, output);
        }
        fprintf(output, "\n");
    }
    fclose(output);
    return 0;
}

int validate(int color_value) {
    int temp = color_value % (color_range + 1);
    if (temp < 0) {
        temp += color_range + 1;
    }
    return temp;
}
