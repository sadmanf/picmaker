#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<math.h>
int main(){
  int fd = open("coolimg.ppm",O_WRONLY | O_APPEND | O_CREAT , 0600);
  write(fd,"P3 500 500 255\n",strlen("P3 500 500 255\n"));
  int y = 0;
  int x = 0;
  for (y = 0; y < 500; y++){
    for (x = 0; x < 500; x++){
      //will make fancy later
      //char stuff[12] = "255 0 0 ";
      char stuff[12];
      sprintf(stuff,"%d %d %d ",y%255, x%255, 255);
      write(fd,stuff,strlen(stuff));
    }
  }
  close(fd);
  return 0;
}
