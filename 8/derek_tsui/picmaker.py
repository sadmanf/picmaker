
rows = 100
cols = 100

output = "P3 %d %d %d \n" % (rows, cols, 255)

for i in range(rows):
    color = ""
    for j in range(cols):
        color = "%d %d %d " % (i+j, j*2, j%10)
        output += color
    output += "\n"


fo = open("foo.ppm", "wb")
fo.write(output);
fo.close()
