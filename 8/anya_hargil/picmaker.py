import math

def picmaker(width, height):
    f = open("pic.ppm", "w")
    w = width
    h = height
    f.write("P3\n" + str(w) + " " + str(h) + "\n255\n")
    for i in range(w):
        for j in range(h):
            f.write(str((math.pow(i, 2)+math.pow(j, 2))%256) + " " + str((math.pow(i, 2)+math.pow(j, 2))%256) + " " + str((math.pow(i, 2)+math.pow(j, 2))%256) + " ")
        f.write("\n")
    f.close()

picmaker(510, 510)
