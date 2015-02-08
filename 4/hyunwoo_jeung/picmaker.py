import math
import random

x = 500
y = 500
text = "P3\n500 500\n255\n"
for m in range(y):
    for n in range(x):  
        a = abs(math.sin(math.log10((n+1)*(m+1)))) * 255
        b = abs(math.cos(math.log10((n+1)*(m+1)))) * 255
        c = abs(math.tan(math.log10((n+1)*(m+1)))) * 255
        text += " %d %d %d "%(a,b,c)

f = open("pic.ppm","w")
f.write(text)
f.close()
