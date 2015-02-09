import math
def picmaker(filename, pixels):
    headers = "P3 500 500 255"
    f = open(filename+".ppm", 'w')
    f.truncate()
    f.write(headers)
    f.write(pixels)
    f.close()

def sqrt():
    pixels = ""
    for i in range(0,500):
        for j in range(0,500):
            pixels += pixel(math.sqrt((i**2))%255,math.sqrt((j**2))%255,math.sqrt(((i**2)+(j**2)))%255)
    return pixels

def pixel(r, g, b):
    return "(%d, %d, %d)" % (r, g, b)
    
picmaker("stripes", sqrt());
