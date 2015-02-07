// I used a nonstandard library to make this 
// compile with gcc image.c -lm
// The tag has to go at the end for some reason
// Worth the hassle for the psychedelic cosine image

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
int main() {
  int fd = open("img.pbm", O_WRONLY | O_CREAT |O_TRUNC);
  char line[4096];
  sprintf(line, "P3\n600 600\n255\n");
  write(fd, line, strlen(line));
  int i;
  int red, blue, green;
  for (i = 0; i < 600; i++) {
    int j;
    for (j = 0; j < 600; j++){
      red = (int) ((cos (1.0 / 50 * (i + 2j)) + 1) * 127);
      blue = (int) ((cos (1.0 / 46 * (2i + j)) + 1) * 127);
      green = (int) ((cos (1.0 / 100 * (3i + 2j)) + 1) * 17);
      sprintf(line, "%d %d %d ", red, green, blue);
      write(fd, line, strlen(line));
    }
  }
  close(fd);
  return 0;
}
