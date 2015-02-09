#took advantage of the Moire effect to generate elaborate image with minimal code
import math
s = ''
for i in range(0, 500):
    for j in range(0, 500):
        s += str(int(50*(math.cos((math.pow(i-250,2)/300.0+math.pow(j-250,2)/300.0))+1)+0.5)) + ' '
        s += str(int(150*(math.cos((math.pow(i-250,2)/100.0+math.pow(j-250,2)/100.0))+1)+0.5)) + ' '
        s += str(int(50*(math.cos((math.pow(i-250,2)/200.0+math.pow(j-250,2)/200.0))+1)+0.5)) + ' '
s = 'P3 500 500 255 ' + s
f = open('pic.ppm', 'w')
f.write(s)
f.close
