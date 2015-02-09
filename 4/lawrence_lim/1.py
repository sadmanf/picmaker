import random

width = 500
height = 500
colormax = 255

class Pixel:
    def __init__(self,img,x,y,r,g,b):
        self.img = img
        self.x = x
        self.y = y
        self.r = r
        self.g = g
        self.b = b
        self.done = False
    def setrgb(self,r,g,b):
        self.r = r
        self.g = g
        self.b = b
    def setdone(self,v):
        self.done = v
    def isdone(self):
        return self.done
    def posstr(self):
        return "(%(x)s,%(y)s)" % {"x":self.x, "y":self.y}
    def neighbors(self):
        ret = []
        if self.img.valid(self.x-1,self.y):
            ret.append(self.img.getpixel(self.x-1,self.y))
        if self.img.valid(self.x+1,self.y):
            ret.append(self.img.getpixel(self.x+1,self.y))
        if self.img.valid(self.x,self.y-1):
            ret.append(self.img.getpixel(self.x,self.y-1))
        if self.img.valid(self.x,self.y+1):
            ret.append(self.img.getpixel(self.x,self.y+1))
        return ret
    

class Image:
    def __init__(self,w,h,c):
        self.w = w
        self.h = h
        self.c = c
        self.p = []
        for y in range(self.h):
            row = []
            for x in range(self.w):
                row.append(Pixel(self,x,y,0,0,0))
            self.p.append(row)
    def getpixel(self,x,y):
        #return self.p[y][x] #intended behavior, but not nearly as cool
        return self.p[x][y] #looks much cooler, only works on squares
    def setpixel(self,x,y,r,g,b):
        curp = self.getpixel(x,y)
        curp.setrgb(r,g,b)
    def valid(self,x,y):
        return (x>=0 and y>=0 and x<self.w and y<self.h)
    def headstr(self):
        r = ""
        r+= "P3\n"
        r+= "%(w)s %(h)s\n" % {"w":self.w, "h":self.h}
        r+= "%(c)s\n" % {"c":self.c}
        return r
    def rgbstr(self):
        r = ""
        for y in range(self.h):
            for x in range(self.w):
                pixel = self.getpixel(x,y)
                r+= "%(r)s %(g)s %(b)s " % \
                    {"r":pixel.r, "g":pixel.g, "b":pixel.b}
            r+="\n"
        return r
    def imgstr(self):
        return self.headstr() + self.rgbstr()
    def yolo(self):
        startp = []
        curp = []
        nextp = []
        for i in range(10):
            x = random.randrange(0,width)
            y = random.randrange(0,height)
            r = random.randrange(0,colormax+1)
            g = random.randrange(0,colormax+1)
            b = random.randrange(0,colormax+1)
            self.setpixel(x,y,r,g,b)
            #self.getpixel(x,y).setdone(True)
            curp.append(self.getpixel(x,y))
            startp.append(self.getpixel(x,y))
        while len(curp)>0:
            for p in curp:
                for n in p.neighbors():
                    if not n.isdone():
                        nextp.append(n)
                    n.setrgb(p.r,p.g,p.b)
                    n.setdone(True)
            curp = nextp
            nextp = []
        #for p in startp:
        #    p.setrgb(255,0,255)
        #    for n in p.neighbors():
        #        n.setrgb(255,0,255)

image = Image(width,height,colormax)
image.yolo()
outs = image.imgstr()

outf = open("1.ppm","w")
outf.write(outs)
outf.close()
