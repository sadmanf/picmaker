import math

def picmaker(filename, pixels):
    headers = "P3 500 500 255"
    f = open(filename+".ppm", 'w')
    f.truncate()
    f.write(headers)
    f.write(pixels)
    f.close()

def pixelate():
    pixels = ""
    for y in range(500):
        for x in range(500):
            r = (math.sqrt(abs(250 - x) ** 2)) % 255
            g = (math.sqrt(abs(250 - y) ** 2)) % 255
            b = (math.sqrt( (abs(250 - x) ** 2) + (abs(250 - y) ** 2))) % 255 
            pixels += " %d  %d  %d " % (r,g,b)
    return pixels

picmaker("pic", pixelate())
