import math
import random


def distance(p0x,p0y, p1x,p1y):
    return math.sqrt((p0x - p1x)**2 + (p0y - p1y)**2)

width = 512
height = 512
code = "P3\n%d %d\n255\n"%(width,height)
r=random.randint(0,255)
for i in range(width):
    for j in range(height):
        if abs( i-j)<20:
            r=0
            g= 256*((distance(0,0,i,j) + 1)/distance(0,0,width,height))
            b=0
        elif abs((width-i)-j)<20:
            r=(256-i/2)%256
            g= 25
            b=i/2%256 
        elif j%64 >32:
            r=i/2%256
            g= 256*((distance(0,0,i,j) + 1)/distance(0,0,width,height))
            b=0
        else:
            r=0
            g= 256*((distance(0,0,i,j) + 1)/distance(0,0,width,height))
            b=(256-i/2)%256
        code+="%d %d %d "%(r,g,b)

f = open("picture.ppm","w")
f.write(code)
f.close()
