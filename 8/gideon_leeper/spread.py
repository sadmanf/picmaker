import random, Queue

random.seed(14)
xdim = ydim = 500
seeds = 50

queue = Queue.Queue()
color = [[-1 for x in range(xdim)] for y in range(ydim)]
rgb = [[random.randint(0, 255) for i in range(3)] for c in range(seeds)]
init = [(random.randint(0, xdim-1), random.randint(0, ydim-1)) for s in range(seeds)]

def update():
	(x, y) = queue.get()
	for (xp, yp) in [(x, y-1), (x+1, y), (x, y+1), (x-1, y)]:
		if 0 <= xp < xdim and 0 <= yp < ydim and color[yp][xp] == -1:
			color[yp][xp] = color[y][x]
			queue.put((xp, yp))

for i in range(seeds):
	(x, y) = init[i]
	queue.put((x, y))
	color[y][x] = i

while not queue.empty():
	update()

f = open("design.ppm", "w")
f.write("P3 " + str(xdim) + " " + str(ydim) + " 255\n")
for y in range(ydim):
	for x in range(xdim):
		for b in rgb[color[y][x]]:
			f.write(str(b) + " ")
		f.write("\n")
f.close()
