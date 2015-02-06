'''
Ivy Wong
MKS66 pd 4
Work 0
'''

img = open('img.ppm','wb')

img.write("P3 500 500 255 \n")

row = ""
for i in range(500):
    for j in range(500):
        r = i % 255
        g = j % 255
        b = 255
        img. write("{0} {1} {2} ".format(r, g, b))

img.close()
#print img.read()
