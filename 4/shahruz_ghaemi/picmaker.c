#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

int main(){
  int fd, i, j, r, g, b;

  fd = open("pic.ppm", O_CREAT | O_WRONLY | O_TRUNC, 0664);
  char line[256];

  write(fd,"P3 500 500 255 ",16);

  for(i = 0; i<500; i++){
    for(j = 0; j<500; j++){
      
      r = 255;
      g = j%255;
      b = i%255;
      sprintf(line, " %d %d %d", r, g, b);
      write(fd, line, strlen(line));
    }
  }
  close(fd);
  return 0;
}
