#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int isCircle(int x, int y, int newX, int newY, int radius);

int main() {
  int pic = open("image.ppm", O_RDWR | O_TRUNC | O_CREAT | 0664 );
  char init[255] = "P3 500 500 255 "; 
  write(pic, init, strlen(init));

  int x = 0;
  int y = 0;

  char color[255] = "0 0 255 ";
  char colo[255] = "0 0 0 ";
  
  
  for(x = 0; x < 500; x++) {
    for(y = 0; y < 500; y++) {
      //write(pic, colo, strlen(colo));
      /*
      if(x > 100 && x < 400 && y > 100 && y < 400)
	write(pic, color, strlen(color));
      else 
      	write(pic, colo, strlen(colo));
      */
      
      if (isCircle(250, 250, x, y, 500))
	write(pic, color, strlen(color));
      else
	write(pic, colo, strlen(colo));
      
    }
  }
  

  //printf("%d\n", isCircle(250, 250, 50, 50, 100));

  close(pic);

  return 0;
}

int isCircle(int x, int y, int newX, int newY, int radius) {
  int dx = newX - x;
  int dy = newY - y;

  if ((dx*dx) + (dy*dy) <= radius)
    return 1;
    
  return 0;
}
