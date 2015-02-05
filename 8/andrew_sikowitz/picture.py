import math

s = "P3\n512 512\n255\n"

for i in range(512):
    for j in range(512):
        x = i-256
        y = j-256
        if abs(round(x*x + y*y) % 25) < 10:
            s += "0 0 0 "
        else:
            s += "255 0 0 "
    s += "\n"

f = open("pic.ppm","w")
f.write(s)
f.close()
