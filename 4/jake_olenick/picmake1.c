#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define PI 3.1415926535

int main(){

  int fd = open("pic.ppm",O_CREAT | O_WRONLY | O_TRUNC,0644);

  char line[12];
  
  int x;
  int y;

  write(fd,"P3 500 500 255 ",16);
  for(y = 0;y<500;y++){
    for(x = 0;x<500;x++){

      float X = (float)x / 500.0;
      float Y = (float)y / 500.0;
      
      float a = sin(2 * PI * X * x) * 255.0;
      float b = cos(2 * PI * Y * y) * 255.0;
      
      sprintf(line," 255 %d %d ",abs(floor(a)),abs(floor(b)));
      write(fd,line,strlen(line));

    }
  }


}
