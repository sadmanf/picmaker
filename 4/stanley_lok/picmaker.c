#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
  
  int fd = open("pic.ppm", O_CREAT | O_WRONLY | O_TRUNC, 0644);

  char header[1024];
  
  sprintf( header, "P3 500 500 255\n");
  write(fd, header, strlen(header));

  int r = 0;
  int g = 0;
  int b = 0;

  int i,j;

  for(i = 0; i < 500; i++){
    for(j = 0; j < 500; j++){
      // pic 1
      r =((j^i) ^ (i&j)) % 255;
      g = (((r * j) ^ (r * j)) & (r * j)) % 255;
      b = (((g * i) ^ (g * j)) ^ (i < j)) % 255;
      
      
      sprintf(header,"%d %d %d\n",r,g,b);
      write(fd, header, strlen(header));
    }
  }

  close(fd);
}
