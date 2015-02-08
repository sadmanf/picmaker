#ifndef DRAWING_H
#define DRAWING_H

#define MAX_HSV 1536

class Surface {
	public:
		int width, height;
		int *raster;

		Surface(int width, int height);
		int *index(int x, int y); //Indexes into the raster
		void write_to_file(const char *filename); //Writes rgb data to file
};

void make_hsv_to_rgb(int *ptr); //converts the pixel being pointed to

enum e_color {
	C_R = 0, C_G, C_B
};

enum e_hsv {
	C_H = 0, C_S, C_V
};

#endif
