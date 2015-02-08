#include <iostream>
#include <fstream>

#include <cmath>
#include <cstdlib>
#include <cstdio>

#include "drawing.h"

#define MAX_HSV 1536
#define PI 3.14159265358979323846264

using namespace std;

class ControlPoint {
	public:
	int x, y;
	int param; //C_H, C_S, or C_V
	double (*alpha_func)(double);
	double (*h_func)(double);
	double (*s_func)(double);
	double (*v_func)(double);
};

double dist(int x, int y, ControlPoint cp) {
	int dx = x - cp.x;
	int dy = y - cp.y;
	return sqrt(dx * dx + dy * dy);
}

int init_control_points(ControlPoint *controls);//Assumes controls is big enough

int main() {
	int width = MAX_HSV;
	int height = 256 * 3;

	Surface s (width, height);

	/* HSV Test pattern
	for(int x = 0; x < s.width; x++) {
		for(int y = 0; y < s.height; y++) {
			int *pix = s.index(x, y);
			pix[C_H] = x % MAX_HSV;
			pix[C_S] = 255 - 40 * (y / 256);
			pix[C_V] = 255 - (y % 256);
		}
	}
	*/

	ControlPoint controls[50];
	int numpoints = init_control_points(controls);

	//Set gradient
	for(int x = 0; x < s.width; x++) {
		for(int y = 0; y < s.height; y++) {

			for(int i = 0; i < numpoints; i++) {
				int new_hsv[3];
				int *pix = s.index(x, y);

				double d = dist(x, y, controls[i]);
				double alpha = controls[i].alpha_func(d);

				new_hsv[C_H] = controls[i].h_func(d);
				new_hsv[C_S] = controls[i].s_func(d);
				new_hsv[C_V] = controls[i].v_func(d);

				make_hsv_to_rgb(new_hsv);

				pix[C_R] = pix[C_R] * (255 - alpha) + new_hsv[C_R] * alpha;
				pix[C_G] = pix[C_R] * (255 - alpha) + new_hsv[C_G] * alpha;
				pix[C_B] = pix[C_R] * (255 - alpha) + new_hsv[C_B] * alpha;

			}
		}
	}

/*	//HSV -> RGB
	for(int x = 0; x < s.width; x++) {
		for(int y = 0; y < s.height; y++) {
			int *pix = s.index(x,y);
			make_hsv_to_rgb(pix);
		}
	}
*/

	s.write_to_file("out.ppm");
	cout << "Done" << endl;
}

double fade(double d) {
	if(d <= 300) 
		return 5 * sqrt(300 - d);
	else
		return 0;
	//(int)(200 * 50 / (distance + 50));
}

double rainbow(double d) {
	return (int)(200 * sin(d * PI / 100) + MAX_HSV) % MAX_HSV;
}

double soft_blue(double d) {
	return 100 * log(d + 1000) + 300;
}

double one(double d) { return 1;}
double f_255(double d) { return 255;}

int init_control_points(ControlPoint *controls) {//Assumes controls is big enough
	int numpoints = 0;

	controls[numpoints].x = 200;
	controls[numpoints].y = 200;
	controls[numpoints].param = C_H;
	controls[numpoints].h_func = rainbow;
	controls[numpoints].s_func = f_255;
	controls[numpoints].v_func = f_255;
	controls[numpoints].alpha_func = fade;
	numpoints++;

	controls[numpoints].x = 1300;
	controls[numpoints].y = 400;
	controls[numpoints].param = C_H;
	controls[numpoints].h_func = soft_blue;
	controls[numpoints].s_func = f_255;
	controls[numpoints].v_func = f_255;
	controls[numpoints].alpha_func = one;
	numpoints++;

	return numpoints;
}
