#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
int main(){
	int fd=open("yo.ppm", O_CREAT|O_WRONLY, 0644); //the file
	int maxx=500; //max x value
	int maxy=500; //max y value
	int maxc=255; //max color value
	char s[10000]="P3\0";
			//char temp[50];
	sprintf(s+strlen(s)," %d",maxx);
	sprintf(s+strlen(s)," %d",maxy);
	sprintf(s+strlen(s)," %d\n",maxc);
	write(fd,&s,strlen(s));
	int r=0;
	int g=0;
	int b=55;
	int i;
	int x=1;
	int y=1;
	for (y=maxy/2; y > -1 * maxy/2; y--){
		for (x=maxx/2; x> -1 * maxx/2; x--){
				b=0;
				r=0;
				g=0;	
				//b%=maxc;
				//r=maxc-b;
				//g=99;
				//if ((pow((y-3),2)+pow((x-3),2))==9)
				
				if (y>0 && (abs(pow(y,1.0/2)-x)<2 || abs(pow(y,1.0/2)+x)<2))
					r=255;
				if (pow(pow(x,2)+pow(y,2),1.0/2)<=144 && pow(pow(x,2)+pow(y,2), 1.0/2)>=81)
					b=255;
				if (y==(int)(20*sin(x)))
					g=255;
				sprintf(s,"%d",r);
				sprintf(s+strlen(s)," %d",g);
				sprintf(s+strlen(s)," %d\n",b);
				write(fd,&s,strlen(s));
				//printf("%d\n",b);
		}
	}
	//write(fd, &s, strlen(s));
	//printf("%d\n",strlen(s));
	close(fd);
}
