import random

f = open ("pic.ppm", 'w')
f.write ("P3\n500 500\n255\n")

i = 500 * 500
n = random.randint (0, 255)
x = n%3

while i > 0:
    if x == 0:
        r = i%255
        g = n
        b = n
    elif x == 1:
        r = n
        g = i%255
        b = n
    else:
        r = n
        g = n
        b = i%255
        
    t = ("%d %d %d "%(r, g, b))
    i = i - 1
    f.write (t)

f.close()
