import random
import math
pic = "P3\n 500\n 500\n 255\n"

c1 = random.random() * 256 #Same throughout
for i in range(0, 500):
    for j in range(0, 500):
        c2 = random.random() #Updates every pixel
        
        #Circle Stuff: 62500 = (x - 250)^2 + (y - 250)^2
        y1 = int(math.pow(62500 - math.pow(j - 250, 2), 0.5)) + 250 #250-500
        y2 = -int(math.pow(62500 - math.pow(j - 250, 2), 0.5)) + 250 #0-250

        if (i >= y1 or i <= y2): #Outside of the circle
            r = math.pow(c1 + i, 2) % 256
            g = math.pow(c1 + j, 2) % 256
            b = math.pow(c1 + i + j, 2) % 256
        elif ((i >= y1 - 50 and i <= y1 + 50) or (i >= y2 - 50 and i <= y2 + 50)): #Border of the circle
            r = 0
            g = 0
            b = 0
        else: #Inside of the circle
            r = (c2 * i) % 256
            g = (c2 * j) % 256
            b = (c2 * abs(i - j)) % 256
            
        pic = pic + "%d %d %d "%(r, g, b)

f = open("pic.ppm", "w")
f.write(pic)
f.close()
