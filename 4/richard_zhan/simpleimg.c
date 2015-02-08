#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<math.h>
double distance(int xi, int yi, int xj, int yj){
  double d;
  d = sqrt(pow((double)xi-(double)xj,2) +pow((double)yi-(double)yj,2)); 
  return d;
}
int[][] circle_draw(int x, int y, int r){
  int circle_parts[100000000][2];
  int parts = 0;
  double angle;
  angle = 0.0;
  while (angle < 2*M_PI){
    circle_parts[parts][0] = (int)sin(angle)*r;
    circle_parts[parts][1] = (int)cos(angle)*r;
    angle+=.1;
  }
  return circle_parts;
}
char isin(int val, int pos, int arr[100000000][2]){
    int i;
    for (i=0; i < 100000000*4; i++) {
        if (arr[i][pos] == val)
            return 1;
    }
    return 0;
}
int main(){
  /* int xi = 0; */
  /* int yi = 30; */
  /* int xj = 40; */
  /* int yj = 0; */
  /* double d = distance(xi,yi,xj,yj); */
  /* printf("%f\n",d); */
  int fd = open("coolimg.ppm",O_WRONLY | O_APPEND | O_CREAT , 0600);
  write(fd,"P3 500 500 255\n",strlen("P3 500 500 255\n"));
  int y = 0;
  int x = 0;
  int circle[100000000][2] = circle_draw(250,250,150);
  for (y = 0; y < 500; y++){
    for (x = 0; x < 500; x++){
      //will make fancy later
      //char stuff[12] = "255 0 0 ";
      char stuff[12];
      if (isin(y,0,circle)){
	sprintf(stuff,"%d %d %d ",0,0,0);
      }
      else{
	sprintf(stuff,"%d %d %d ",y%255, x%255, 255);
      }
      write(fd,stuff,strlen(stuff));
    }
  }
  close(fd);
  return 0;
}
