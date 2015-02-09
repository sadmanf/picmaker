def drawpic(height,width):
    f= open("image.ppm","w")
    htemp=height
    f.write("P3 "+str(height)+ " "+str(width)+" 500\n")
    while width >0:
        while height >0:
            if (width /100) % 2 == 0 and (height /100) % 2 == 0  :
                 f.write( str(500 - (height)%5000) +" "+ str(500 -width% 500)+" "+  str( 500 - width*height %500) +"\n")
        
            else:
                f.write( str((width% 500)) +" "+ str((height)%500)+" "+  str(width*height) +"\n")
            height -=1
        height=htemp
        width-=1
    f.close()


drawpic(500,500)