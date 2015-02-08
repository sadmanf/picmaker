import java.io.BufferedOutputStream;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.Random;

class Picmaker {
	public static void main(String[] args) {
		final byte r = 0, g = 1, b = 2;
		final int width = 640, height = 480, maxval = 255;
		
		//The following two try blocks create the same image, encoded in different formats
		try {//ASCII
			NetpbmPPM.toFileASCII("gradient.ascii.ppm", width, height, maxval, (BufferedWriter writer) -> {
				for (int y = 0; y < height; y++) {
					for (int x = 0; x < width; x++) {
						String pixel = "" + 255 + " " + (x % 256) + " " + (y % 256) + (x < width - 1 ? " " : "\n");
						try {writer.write(pixel, 0, pixel.length());}
						catch (IOException e) {System.out.println(e);}
					}
				}
				return null;
			});
		} catch (IOException e) {System.out.println(e);}
		try {//Binary
			NetpbmPPM.toFileBinary("gradient.bin.ppm", width, height, maxval, (BufferedOutputStream output) -> {
				for (int y = 0; y < height; y++) {
					for (int x = 0; x < width; x++) {
						try {output.write(new byte[] {(byte) 255, (byte) (x % 256), (byte) (y % 256)}, 0, 3);}
						catch (IOException e) {System.out.println(e);}
					}
				}
				return null;
			});
		} catch (IOException e) {System.out.println(e);}
		
		try {
			NetpbmPPM.toFileBinary("random.ppm", width, height, maxval, (BufferedOutputStream output) -> {
				Random random = new Random();
				for (int y = 0; y < height; y++) {
					for (int x = 0; x < width; x++) {
						byte[] pixel = new byte[3];
						random.nextBytes(pixel);
						try {output.write(pixel, 0, 3);}
						catch (IOException e) {System.out.println(e);}
					}
				}
				return null;
			});
		} catch (IOException e) {System.out.println(e);}
		
		try {
			NetpbmPPM.toFileBinary("something.ppm", width, height, maxval, (BufferedOutputStream output) -> {
				for (int y = 0; y < height; y++) {
					for (int x = 0; x < width; x++) {
						try {output.write(new byte[] {(byte) (x % 256), (byte) ((2 * x) % 256), (byte) ((3 * x) % 256)}, 0, 3);}
						catch (IOException e) {System.out.println(e);}
					}
				}
				return null;
			});
		} catch (IOException e) {System.out.println(e);}
	}
}
