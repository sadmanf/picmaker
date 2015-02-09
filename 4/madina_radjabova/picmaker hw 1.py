import sys
from random import randrange

def write_img():
        f = open("intro.ppm", 'w')
        xres = 500
        yres = 500
        f.write("P3\n" + str(xres) + ' ' + str(yres) + "\n255\n")
        for x in range(xres):
            pixrow = 1
            flip = False
            for y in range(yres):
                f.write('0 ' + str(pixrow % 255) + ' 0 ')
                if pixrow > 255:
                    flip = True
                if flip:
                    pixrow -= 1
                else:
                    pixrow += 1
            f.write('\n')
            #print pixrow
        f.close()

write_img()
