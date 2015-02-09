import math
import random

#imagemagick -> emacs [commandline photoshop]
def createpic(fname, pd, leng, width):
    f = open(str(fname), 'w')

    header = "P3\n%d %d\n255\n"%(leng,width)
    f.write(header)
    f.write(pd)
    f.close()

def sq(x):
    return x*x

def dist (x,y,x1,y1):
    return int(math.sqrt(sq(x-x1) + sq(y-y1)))

def noise (fname,leng = None, width = None):
    try:
        leng = int(leng)
        width = int(width)
    except:
        leng = 500
        width = 500
    if leng == None:
        leng = 500
    if width == None:
        width = 500
    pixdata = ""
    i=0
    while i < leng*width:
        y = 0
        #or :
        #pixdata += "%s "% str(random.randint(0, 256))
        while y<3:
            pixdata +=  str(random.randint(0, 256))
            pixdata += " "
            y+=1
        i += 1
    createpic(fname, pixdata, leng, width)
    print "done"

def diagonals(fname, leng = None, width = None):
    if leng == None:
        leng = 500
    if width == None:
        width = 500 
    pixdata = ""
    i=0
    while i < int(leng)*int(width):
        y = 0
        while y<3: #for each RGB value (there are three of them...)
            pixdata += "%d "%(i%255)
            y += 1
        i += 1
    createpic(fname, pixdata, leng, width)
   
def funkydiag(fname, leng = None, width = None):
    if leng == None:
        leng = 500
    if width == None:
        width = 500 
    pixdata = ""
    i=0
    while i < int(leng)*int(width):
        #RED
        pixdata += "%d "%(i*i%111)
        pixdata += " "
        #GREEN
        pixdata += "%d "%(i*i%11)
        pixdata += " "
        #BLUE
        pixdata += "%d "%(i*i%111)
        pixdata += " "
        i += 1

    createpic(fname, pixdata, leng, width)


def circlely(fname, leng = None, width = None):
    if leng == None:
        leng = 500
    if width == None:
        width = 500 
    pixdata = ""
   
    y = 0
    while y < width:
        x = 0
        while x < leng:
            #RED
            pixdata += "%d "%(dist(x,y,250,250)%250)
            pixdata += " "
            #GREEN
            pixdata += "%d "%(dist(x,y,0,0)%35)
            pixdata += " "
            #BLUE
            pixdata += "%d "%(dist(x,y,250,250)%250)
            pixdata += " "
            x += 1
        y+=1

    createpic(fname, pixdata, leng, width)



 
circlely("circle.ppm")
#diagonals("diagonal.ppm")
#funkydiag("diag.ppm")
#noise("noise.ppm")
