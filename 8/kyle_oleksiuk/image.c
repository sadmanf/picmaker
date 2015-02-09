#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


void main(){
  
  char buf[10];
  int xres, yres, key;

  xres = 500;
  yres = 500;
  
  key = open("sin.ppm", O_CREAT | O_WRONLY, 0664);
  sprintf(buf, "P3\n%d %d\n%d\n", xres, yres, 255);
  write(key, buf, strlen(buf));
  
  int a, c, red, green, blue; 
  
  for(a=0; a<yres; a++){
    for(c=0; c<xres; c++){
		
		red = (int)(c*a)%256;
		green = (int)(sin(c))%256;
		blue = (int)(green)%256;

    	sprintf(buf, "%d %d %d\t", red, green, blue);
    	write(key, buf, strlen(buf));
    }    
  }
  close(key);
}