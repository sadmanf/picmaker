import math,random
from random import randint


swag = open ('picmaker.ppm', 'w')
swag.write ("P3\n600 600\n255\n")

for i in range (600):
    for j in range (600):
        red = str(random.randrange(0,255))
        green = str(random.randrange(0,255))
        blue = str(random.randrange(0,255))
        swag.write ( red + " " + green + " " + blue + "\n")

swag.close()

swag = open ('picmaker2.ppm', 'w')
swag.write ("P3\n600 600\n255\n")

red = random.randrange(0,255)
green = random.randrange(0,255)
blue = random.randrange(0,255)

for i in range (600):
    if ( i % 2 == 0):
        red = red + randint(0,5) % 255
    if ( i % 3 == 0):
        green = green + randint(0,5) % 255
    if ( i % 5 == 0):
        blue = blue + randint(0,5) % 255
    for j in range (600):
        
        swag.write ( str(red) + " " + str(green) + " " + str(blue) + "\n")

swag.close()


