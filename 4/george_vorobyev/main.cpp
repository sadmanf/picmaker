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
	int width = 1000;
	int height = 1000;

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

				pix[C_R] = (pix[C_R] * (255 - alpha) + new_hsv[C_R] * alpha) / 255;
				pix[C_G] = (pix[C_G] * (255 - alpha) + new_hsv[C_G] * alpha) / 255;
				pix[C_B] = (pix[C_B] * (255 - alpha) + new_hsv[C_B] * alpha) / 255;

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

double norm(double d, int max) { //normalizes hue/alpha
	if(d != d) { //if d = NaN
		return 0;
	}

	double old_d = d;
	if(d < 0) {
		
		d += -1 * max * ((int)d / max);
		d += max;
	}
	if(d < 0) {
		cerr << "MAAAN " << old_d << endl;
	}
	d = ((int)d) % max;
	return d;
}

double max(double a, double b) {
	if(a < b) 
		return b;
	else 
		return a;
}
double min(double a, double b) {
	if(a < b) 
		return a;
	else 
		return b;
}

double fade(double d) {
	if(d <= 350) 
		return max(min(255, 255 * (1.6 - (10 / (40 - d / 10))) ), 0);
	else
		return 0;
	//(int)(200 * 50 / (distance + 50));
}

double rainbow(double d) {
	return min(d * 10, MAX_HSV - 1);
}

double squiggle(double d) {
	return norm(200 * sin(d * PI / 100) - 300, MAX_HSV);
}

double soft_blue(double d) {
	return norm(max(200 * log(1800 - d) + 1100, 0) , MAX_HSV);
}


double orange(double d) { return 100; }
double red(double d) { return 0; }


double one(double d) { return 1;}
double f_255(double d) { return 255;}
double f_200(double d) { return 200;}
double f_150(double d) { return 150;}
double f_100(double d) { return 100;}
double f_50(double d) { return 50;}
double f_0(double d) { return 0;}
double stripes(double d) { return ((int)(d + 30) / 100) % 2 ? 0 : 255; }
double border(double d) { 
	const double start = 250;

	if(d != d) { //if d = NaN
		return 0;
	}

	if (d < start) {
		return 0;
	}
	
	d -= start;
	d *= 1.12;
	return min(d, 255);
}

double rainbow_circle(double d) {
	const double start = 153;

	if(d != d) { //if d = NaN
		return 0;
	}

	if (d < start) {
		return 255;
	}
	
	d = 255 - (d - start) * 10;
	
	return max(d, 0);
}

int init_control_points(ControlPoint *controls) {//Assumes controls is big enough
	int numpoints = 0;

	//Background
	controls[numpoints].x = 500;
	controls[numpoints].y = 0;
	controls[numpoints].param = C_H;
	controls[numpoints].h_func = soft_blue;
	controls[numpoints].s_func = f_255;
	controls[numpoints].v_func = f_255;
	controls[numpoints].alpha_func = f_255;
	numpoints++;

	//Blue/Magenta circle
	controls[numpoints].x = 500;
	controls[numpoints].y = 500;
	controls[numpoints].param = C_H;
	controls[numpoints].h_func = squiggle;
	controls[numpoints].s_func = f_255;
	controls[numpoints].v_func = f_255;
	controls[numpoints].alpha_func = fade;
	numpoints++;

	//Orange stripes
	controls[numpoints].x = 200;
	controls[numpoints].y = 200;
	controls[numpoints].param = C_H;
	controls[numpoints].h_func = orange;
	controls[numpoints].s_func = f_255;
	controls[numpoints].v_func = f_255;
	controls[numpoints].alpha_func = stripes;
	numpoints++;

	//Full rainbow stripes
	controls[numpoints].x = 650;
	controls[numpoints].y = 650;
	controls[numpoints].param = C_H;
	controls[numpoints].h_func = rainbow;
	controls[numpoints].s_func = f_255;
	controls[numpoints].v_func = f_255;
	controls[numpoints].alpha_func = rainbow_circle;
	numpoints++;

	//Red border
	controls[numpoints].x = 500;
	controls[numpoints].y = 500;
	controls[numpoints].param = C_H;
	controls[numpoints].h_func = red;
	controls[numpoints].s_func = f_200;
	controls[numpoints].v_func = f_150;
	controls[numpoints].alpha_func = border;
	numpoints++;


	return numpoints;
}
