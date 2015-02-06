
def makePic():
    f = open('terrancepic.ppm','w')
    f.write('P3\n512 512\n255\n')
    pixelvals=""
    for x in range(512):
        for y in range(512):
            r = (x+y) % 4
            g = (x+y) % 256
            b = (x+y) % 256
            pixelvals = pixelvals+"%d %d %d %d %d %d "%(r, g, b, r, g, b)
    f.write(pixelvals)
    f.close()

makePic()
