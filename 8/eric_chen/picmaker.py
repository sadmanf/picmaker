def makePicture():
    picture = open("pic.ppm", "w")
    picture.write("P3 \n")
    picture.write("500 500 \n")
    picture.write("255 \n")

    for x in range(500):
        for y in range(500):
            red = abs(x - 255)
            green = x % 255
            blue = abs(y - 255)

            picture.write("%d %d %d " % (red, green, blue))
            picture.write("\n")

    picture.close()


def main():
    makePicture()

if __name__ == '__main__':
    main()
