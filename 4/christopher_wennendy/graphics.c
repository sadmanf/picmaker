#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <fcntl.h>

int main(){
  int fd = open("picture.ppm" , O_WRONLY | O_CREAT | O_TRUNC , 0664);
  write(fd , "P3 500 500 255\n", strlen("P3 500 500 255\n"));
  int x , y; x = 0; y = 0;
  for (y; y < 500; y++){
    for (x; x < 500; x++){
      char pattern[256]; int r , g , b;
      r = (y * x + y) % 255; 
      g = (r * x + r * y + x * y + y * x + x + y) % 255; 
      b = (r * g + g * r + x + y * r) % 255;
      sprintf(pattern , "%d %d %d\n" , r , g , b);
      write(fd , pattern , strlen(pattern));
    }
    x = 0;
  }
  close(fd);
  return 0;
}
