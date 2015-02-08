from grid import Grid
from ppm import PPM
from random import randint

# Main Method
def main():
    # Create Grid Object
    grid = Grid(1000, 1000)

    # Random Noise
    for i in range(grid.width):
        for j in range(grid.height):
            if ( (i + j) % 2 ):
                grid.grid[i][j].set_red_num( randint(0, 255) )
                grid.grid[i][j].set_green_num( randint(0, 255) )
                grid.grid[i][j].set_blue_num( randint(0, 255) )

    # Create PPM
    ppm = PPM(grid)

    # Open file and write PPM
    f = open("pic.ppm", "w")
    f.write( str(ppm) )
    f.close()

# Call Main
main()
