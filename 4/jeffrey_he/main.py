from random import randint

res = ""
f = open("pic.ppm", "w")
f.write("P3\n")
f.write("500 500\n")
f.write("255\n")
last = [randint(0,255), randint(0,255), randint(0,255)]
dr = 1
dg = 2
db = 3
for y in range(0,500):
    for x in range (0,500):
        last = [(last[0] + dr) % 256, (last[1] + dg) % 256, (last[2] + db) %256]
        f.write("%d %d %d " % ( last[0], last[1], last[2]))
    f.write("\n")
f.close()
