x_max = 500
y_max = 500

f = open('first.ppm','wb')

f.write("P3\n{0} {1}\n 255\n".format(x_max,y_max))

grid = [ [ [] for x in range(0,x_max)  ] for y in range(0,y_max)]
#print grid

for y in range(0,y_max):
    for x in range(0,x_max):
        grid[y][x].append(0)

for y in range(0,y_max):
    for x in range(0,x_max):
        grid[y][x].append((5 * x + 1) % 255)
        grid[y][x].append((pow(5,y)+1) % 255)

        
for y in range(0,y_max):
    for x in range(0,x_max):
        f.write("{0} {1} {2} ".format(grid[y][x][0],grid[y][x][1],grid[y][x][2]))


f.close()
