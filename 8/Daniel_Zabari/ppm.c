#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main(){
	int fd=open("yo.ppm", O_CREAT|O_WRONLY, 0644); //the file
	int maxx=100; //max x value
	int maxy=100; //max y value
	int maxc=255; //max color value
	char s[10000]="P3\0";
	char temp[50];
	sprintf(s+strlen(s)," %d",maxx);
	sprintf(s+strlen(s)," %d",maxy);
	sprintf(s+strlen(s)," %d",maxc);
	int r=200;
	int g=100;
	int b=0;
	int i;
	for (i=maxx; i >= 0; i--){
		if (r > 256)
			r=0;
		if (b > 256)
			b=0;
		if (g > 256)
			g=0;
		sprintf(s+strlen(s)," %d",r);
		sprintf(s+strlen(s)," %d",g);
		sprintf(s+strlen(s)," %d",b);
	}
	write(fd, &s, strlen(s));
	close(fd);
}

