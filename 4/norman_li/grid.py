from pixel import Pixel

# Grid Object

class Grid(object):
    # Instance Variables
    width = 0
    height = 0

    # Constructor
    def __init__(self, width, height):
        self.grid = [[Pixel() for i in range(width)] for j in range(height)]
        self.width = width
        self.height = height

    # toString Function
    def __str__(self):
        result = ""

        for i in range(self.width):
            for j in range(self.height):
                result += str( self.grid[i][j] )
                result += " "

            result = result.strip()
            result += "\n"

        return result
