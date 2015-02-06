res = open("res.ppm", 'w')
res.write("P3 \n")
res.write("512 512 \n")
res.write("255 \n")

for x in range(512):
    for y in range(512):
        r = x % 255
        g = x + y % 255
        b = x * y % 255
        res.write("%d %d %d " % (r, g, b))
    res.write("\n")

res.close()
    
