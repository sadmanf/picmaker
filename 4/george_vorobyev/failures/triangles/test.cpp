#include <iostream>
#include <fstream>

#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define MAX_HSV 1536

enum e_color {
	C_R = 0, C_G, C_B
};

enum e_hsv {
	C_H = 0, C_S, C_V
};

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
				ptr[col] = ptr[col] * sat / val;
				ptr[col] = val - ptr[col];
			}
		}
	}
}


class Surface {
public:
	int width, height;
	int *raster;

	//cout << "Woop: ";// << printf("%d", -5 % 3) << endl;

	Surface(int width, int height) {
		this->width = width;
		this->height = height;

		raster = new int[width * height * 3];
	}

	int *index(int x, int y) {
		if(x < 0 || y < 0 || x >= width || y >= height) {
			cerr << "ArrayIndexOutOfBoundsException: " << printf("%d,%d", x, y) << endl;
			exit(-1);
		}
		return raster + (3 * (width * y + x));
	}

	void write_to_file(const char *filename) {
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
};


int main() {
	int width = MAX_HSV;
	int height = 512;

	Surface s (width, height);

	for(int x = 0; x < s.width; x++) {
		for(int y = 0; y < s.height; y++) {
			int *pix = s.index(x, y);
			pix[C_H] = x % MAX_HSV;
			pix[C_S] = y / 256 > 0 ? 100 : 255;
			pix[C_V] = 255 - (y % 256);
			make_hsv_to_rgb(pix);
		}
	}

	s.write_to_file("temp.ppm");
	cout << "Done" << endl;
}
