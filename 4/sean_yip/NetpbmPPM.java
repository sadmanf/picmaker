import java.io.BufferedOutputStream;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.function.Function;

class NetpbmPPM {
	/**
	 * Creates a Netpbm PPM image in human-readable ASCII.
	 * <p>
	 * Usage:
	 * <pre>{@code
	 * import java.io.BufferedWriter;
	 * 
	 * try {
	 * 	NetpbmPPM.toFileASCII(String path, int width, int height, int maxval, (BufferedWriter writer) -> {
	 * 		//Your code to generate image
	 * 		//Write the image to file, enclosing the writing part in a try block. Example:
	 * 		for (int y = 0; y < height; y++) {
	 * 			for (int x = 0; x < width; x++) {
	 * 					String pixel = "" + 255 + " " + (x % 256) + " " + (y % 256) + (x < width - 1 ? " " : "\n");
	 * 					try {writer.write(pixel, 0, pixel.length());}
	 * 					catch (IOException e) {
	 * 						//Your exception handler
	 * 					}
	 * 			}
	 * 		}
	 *		return null;
	 * 	});
	 * } catch (IOException e) {
	 * 	//Your exception handler
	 * }
	 * }</pre>
	 * @param path path of file
	 * @param width width of image
	 * @param height height of image
	 * @param maxval maximum color value
	 * @param image code to generate image and write to file
	 * @throws IOException throws <a href="http://docs.oracle.com/javase/8/docs/api/java/io/BufferedWriter.html">BufferedWriter</a>'s exceptions
	 */
	static void toFileASCII(String path, int width, int height, int maxval, Function<BufferedWriter, Void> image) throws IOException {
		BufferedWriter writer = Files.newBufferedWriter(Paths.get(path), StandardCharsets.US_ASCII);
		writer.write("P3 " + width + " " + height + " " + maxval + "\n");
		image.apply(writer);
		writer.close();
	}
	
	/**
	 * Creates a Netpbm PPM image in binary.
	 * <p>
	 * Usage:
	 * <pre>{@code
	 * import java.io.BufferedOutputStream;
	 * 
	 * try {
	 * 	NetpbmPPM.toFileBinary(String path, int width, int height, int maxval, (BufferedOutputStream output) -> {
	 * 		//Your code to generate image
	 * 		//Write the image to file, enclosing the writing part in a try block. Example:
	 * 		for (int y = 0; y < height; y++) {
	 * 			for (int x = 0; x < width; x++) {
	 * 					try {output.write(new byte[] {(byte) 255, (byte) (x % 256), (byte) (y % 256)}, 0, 3);}
	 * 					catch (IOException e) {
	 * 						//Your exception handler
	 * 					}
	 * 			}
	 * 		}
	 *		return null;
	 * 	});
	 * } catch (IOException e) {
	 * 	//Your exception handler
	 * }
	 * }</pre>
	 * @param path path of file
	 * @param width width of image
	 * @param height height of image
	 * @param maxval maximum color value
	 * @param image code to generate image and write to file
	 * @throws IOException throws <a href="http://docs.oracle.com/javase/8/docs/api/java/io/BufferedWriter.html">BufferedWriter</a>'s exceptions
	 */
	static void toFileBinary(String path, int width, int height, int maxval, Function<BufferedOutputStream, Void> image) throws IOException {
		try {
			BufferedWriter writer = Files.newBufferedWriter(Paths.get(path), StandardCharsets.US_ASCII);
			writer.write("P6 " + width + " " + height + " " + maxval + "\n");
			writer.close();
			BufferedOutputStream output = new BufferedOutputStream(Files.newOutputStream(Paths.get(path), StandardOpenOption.APPEND, StandardOpenOption.WRITE));
			image.apply(output);
			output.close();
		} catch (IOException e) {System.out.println(e);}
	}
}