#include <iostream>
#include <fstream>
#include <cstdlib>

#include "drawing.h"

using namespace std;

//First sets rgb by hues
//Then scales down by value
//Then scales up by saturation
void make_hsv_to_rgb(int *ptr) { //converts the pixel being pointed to
	int hue = ptr[C_H];
	int sat = ptr[C_S];
	int val = ptr[C_V];
	if(hue < 0 || hue >= MAX_HSV) {
		cerr << "Invalid hue" << endl;
		hue %= MAX_HSV;
	}
	if(sat < 0 || sat > 255) {
		cerr << "Invalid saturation" << endl;
		sat %= 255;
	}

	for(int col = 0; col < 3; col++) {

		//Set Hue
		{
			int sextant = hue / 256;//0-5
			int remainder = hue % 256;

			//Red rises in sextant 4
			//Green rises in sextant 0
			//Blue rises in sextant 2
			sextant -= (col + 2) * 2;
			sextant += 12;
			sextant %= 6;

			switch (sextant) {
				case 0: {	//rises
					ptr[col] = remainder;
				} break;
				case 1:		//high
				case 2: {
					ptr[col] = 255;
				} break;
				case 3: {	//falls
					ptr[col] = 255 - remainder;
				} break;
				case 4:
				case 5: {	//low
					ptr[col] = 0;
				} break;
			}
		}

		//Adjust for Value and saturation
		{
			ptr[col] = ptr[col] * val / 256;


			if(val != 0) {
				ptr[col] = val - ptr[col];
				ptr[col] = ptr[col] * sat / 256;
				ptr[col] = val - ptr[col];
			}
		}
	}
}


Surface::Surface(int width, int height) {
	this->width = width;
	this->height = height;

	raster = new int[width * height * 3];
}

int *Surface::index(int x, int y) {
	if(x < 0 || y < 0 || x >= width || y >= height) {
		cerr << "ArrayIndexOutOfBoundsException: " << printf("%d,%d", x, y) << endl;
		exit(-1);
	}
	return raster + (3 * (width * y + x));
}

void Surface::write_to_file(const char *filename) {
	ofstream fs;
	fs.open(filename);
	fs << "P6 " << width << " " << height << " 255\n";

	char temp_buff[width * height * 3];
	for(int i = 0; i < width * height * 3; i++) {
		temp_buff[i] = (char) raster[i] % 256;
	}
	fs.write(temp_buff, width * height * 3);
	fs.close();
}
