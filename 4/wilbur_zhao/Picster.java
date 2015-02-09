import java.io.PrintWriter;
import java.io.FileNotFoundException;

public class Picster{

	public static void main(String[] args){
		try {
			PrintWriter writer = new PrintWriter("pic.ppm");
			//
			writer.println("P3 1024 1024 255 ");
			
			for (int i = 0; i < 1024; i++){
				for (int j = 0; j < 1024; j++){
					int ijmix = (i*j) % 256;
					int ijmix2 = (i + j) % 256;
					int ijmix3 = (i*i*j*j) % 256;
					writer.println("" + ijmix + " " + ijmix2 + " " + ijmix3 + " ");
				}
			}
			writer.close();
		} catch (FileNotFoundException E){
			System.out.println("The file pic.ppm does not exist");
		}
	}
	
}
