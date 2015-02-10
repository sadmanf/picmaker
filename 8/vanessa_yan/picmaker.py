import math

arr = []
for x in range(256):
    for y in range(256):
        r = 0
        g = 0
        b = 0
        if (y/10)%2 == 0:
            r = y % 255
        if (x/10)%2 == 0:
            g = x % 255
        g = g + (x*x + y*y)%255
        b = b + (x*x + y*y)%255
        arr.append("{0} {1} {2} ".format(r,g,b))


s = "P3\n256 256\n255\n"
for i in arr:
    s = s + i

f = open("a.ppm", "w")
f.write(s)
f.close()
