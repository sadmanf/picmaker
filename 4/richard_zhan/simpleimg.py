import math
s = "P3 500 500 255\n"
for y in range(500):
    for x in range(500):
        center = (((x+10)/50)*50,((y+10)/50)*50)
        if (math.pow(center[0]*1.0-x,2) + math.pow(center[1]*1.0-y,2) <= 50):
                s += "255 255 255 "
        elif y % 50 >= 45 or y % 50 <= 5 or x % 50 >= 45 or x % 50 <= 5:
            s += "176 176 176 "
        else:
            s += "0 0 0 "
        
    
f = open("coolimg.ppm","w")
f.write(s)
