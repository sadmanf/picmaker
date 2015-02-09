import math
from math import pi

img = open('img.ppm','wb')

xres = 510
yres = 510

data = "P3 {0} {1} 255\n".format(xres, yres)

for x in range(xres):
    for y in range(yres):

        #Circle
        red = int(math.fabs(math.sqrt(math.pow(x-xres/2, 2) + math.pow(y-yres/2, 2))%255-255))
        green = int(math.fabs(math.sqrt(math.pow(x-xres/2, 2) + math.pow(y-yres/2, 2))%255-255))
        blue = 190
        data += "{0} {1} {2} ".format(red, green, blue)

img.write(data)
img.close()
