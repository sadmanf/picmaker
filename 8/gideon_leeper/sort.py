import random

random.seed(1)

colors = [[[random.randint(0, 125), random.randint(0, 255), random.randint(0, 255)] for x in range(500)] for y in range(500)]

for times in range(10):
	for i in range(500):
		colors[i].sort(key=lambda c: (2**16)*c[0] + (2**8)*c[1] + c[2])
	colors = [[colors[y][x] for y in range(500)] for x in range(500)]

f = open("sort.ppm", "w")
f.write("P3 500 500 255\n")
for y in range(500):
	for x in range(500):
		for b in colors[y][x]:
			f.write(str(b) + " ")
		f.write("\n")
f.close()

