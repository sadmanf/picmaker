import sys
from random import random

if len(sys.argv) != 3:
    print 'Usage: {0} <xres> <yres>'.format(sys.argv[0])
    sys.exit()

xres = int(sys.argv[1])
yres = int(sys.argv[2])
f = open('first.ppm', 'wb')
f.write("P3\n{0} {1}\n 1000\n".format(xres, yres)) #header
for x in xrange(xres):
    for q in xrange(yres):
        pixel = "{0} {1} {2}\n".format(x % xres , q % yres, 127)
        f.write(pixel)

print 'Done!'
f.close()
