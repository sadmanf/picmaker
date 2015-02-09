import math,random
from random import randint


swag = open ('picmaker.ppm', 'w') # random pixels mashed together
swag.write ("P3\n600 600\n255\n")

for i in range (600):
    for j in range (600):
        red = str(random.randrange(0,255))
        green = str(random.randrange(0,255))
        blue = str(random.randrange(0,255))
        swag.write ( red + " " + green + " " + blue + "\n")

swag.close()


swag = open ('picmaker2.ppm', 'w') # algorithmic art, image is random pattern (sometimes looks ugly, sometimes looks really nice)
swag.write ("P3\n600 600\n255\n")

red = random.randrange(0,255)
green = random.randrange(0,255)
blue = random.randrange(0,255)


for i in range (600):
    for j in range (600):
        
        r = round(math.fabs(math.sin(i*j*3))* red)
        g = round(math.fabs(math.sin(i*j*2))* green )
        b = round(math.fabs(math.sin(i*j*4))* blue)

        swag.write ( str(r) + " " + str(g) + " " + str(b) + "\n")

swag.close()


