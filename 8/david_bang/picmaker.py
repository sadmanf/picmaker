import math,random


swag = open ('picmaker.ppm', 'w')
swag.write ("P3\n600 600\n255\n")

for i in range (600):
    for j in range (600):
        red = str(random.randrange(0,255))
        green = str(random.randrange(0,255))
        blue = str(random.randrange(0,255))
        swag.write ( red + " " + green + " " + blue + "\n")





swag.close()
