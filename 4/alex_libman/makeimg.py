import math

xSize = 600
ySize = 600
text = "P3\n%d %d\n255\n"%(xSize,ySize)
for i in range(ySize):
    for j in range(xSize):
        a = abs(math.sin(2. * i / ySize * math.pi)) * 255
        b = abs(math.cos(2. * j / xSize * math.pi)) * 255
        c = i % 255
        text += "%d %d %d "%(a,b,c)
f = open("img.ppm","w")
f.write(text)
f.close()
