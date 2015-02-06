pic = open ('pic3.ppm', 'w')

width = 500
height = 500

towrite = ""
towrite += "P3 " + str(width) + " " + str(height) + " 255\n"


for y in range(height):
    for x in range(width):
        
        ycolornum = str(int(255.0*y/height))
        xcolornum = str(int(255.0*x/width))
        
        if int(5.0*y/height) % 2 != 0:
            if int(5.0*x/width)%2 != 0:
                towrite +=  "0" + " " + ycolornum + " " + xcolornum + "\n"
            else:
                towrite +=  xcolornum + " " + "0" +" "+ ycolornum + "\n"
    
        else:
            if int(5.0*x/width)%2 != 0:
                towrite +=  xcolornum + " " + "0" +" "+ ycolornum + "\n"
            else:
                towrite +=  "0" + " " + ycolornum + " " + xcolornum + "\n"

pic.write(towrite)
pic.close
