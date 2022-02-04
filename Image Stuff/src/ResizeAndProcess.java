import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.math.BigInteger;

import javax.imageio.ImageIO;

public class ResizeAndProcess {

	public static void main(String[] args) {
		String name = "jump";
		String type = ".png";

		File original = new File(name+type);

		BufferedImage img = null;
		try {
			img = ImageIO.read(original);
			int numFrames = img.getHeight()/12;
			int [] output = new int[img.getHeight()];

			for(int i = 0; i < img.getHeight(); i++) {
				for(int j = 0; j<img.getWidth(); j++) {
					Color c = new Color(img.getRGB(j, i));
					int threshold = 50;
					if(c.getRed()<threshold&&c.getGreen()<threshold&&c.getBlue()<threshold) {
						output[i]+= (1<<j);
					}
				}
			}

			for(int currentFrame = 0; currentFrame<numFrames; currentFrame++) {
				//System.out.println("uint32_t "+name+(currentFrame+1)+" [] = {             //frame "+(currentFrame+1)+" of "+numFrames);
				for(int i = (12*currentFrame); i<(12*(currentFrame+1)); i++) {
					String binString = "";
					System.out.print("  0x");
					for(int j = 0; j<32; j++) {
						int bit = (output[i]&(1<<j))>>j;
						if(bit==1) {
							binString+="1";
						}
						else {
							//System.out.print(" ");
							binString+="0";
						}
					}
					//System.out.print(binString);
					String hexString = new BigInteger(binString, 2).toString(16);
					String decString = new BigInteger(binString, 2).toString(10);
					System.out.print(hexString);
					if(i<(12*(currentFrame+1)-1))System.out.println(",");
					else {
						System.out.println(" },");
						System.out.print("\n{");
					}
				}	
				//System.out.println("\n};");
				System.out.println("\n");
			}
		}
		catch(IOException e){
			e.printStackTrace();
		}



	}
	static BufferedImage resizeImage(BufferedImage originalImage, int targetWidth, int targetHeight) throws IOException {
		BufferedImage resizedImage = new BufferedImage(targetWidth, targetHeight, BufferedImage.TYPE_INT_RGB);
		Graphics2D graphics2D = resizedImage.createGraphics();
		graphics2D.drawImage(originalImage, 0, 0, targetWidth, targetHeight, null);
		graphics2D.dispose();
		return resizedImage;
	}
	//	BufferedImage img = null;
	//	try {
	//		img = ImageIO.read(original);
	//		//BufferedImage processedImage = new BufferedImage(img.getWidth(), img.getHeight(), BufferedImage.TYPE_INT_ARGB);
	//		//try {
	//			//BufferedImage resized = resizeImage(img, 32,12);
	//			//ImageIO.write(resized, "jpg", new File("new.jpg"));
	//			for(int i = 0; i < img.getHeight(); i++) {
	//				for(int j = 0; j<img.getWidth(); j++) {
	//					Color c = new Color(img.getRGB(j, i));
	//					int threshold = 50;
	//					if(c.getRed()<threshold&&c.getGreen()<threshold&&c.getBlue()<threshold) {
	//						output[i]+= (1<<j);
	//					}
	//				}
	//			}
	//			System.out.println("uint32_t "+name+" [] = {");
	//			for(int i = 0; i<12; i++) {
	//				System.out.print("  0b");
	//				for(int j = 0; j<32; j++) {
	//					int bit = (output[i]&(1<<j))>>j;
	//					if(bit==1)
	//						System.out.print(bit);
	//					else System.out.print(" ");
	//				}
	//				if(i<11)System.out.println(",");
	//				else System.out.println("\n};");
	//			}
	//			
	//			
	////		} catch (IOException e) {
	////			e.printStackTrace();
	////		}
	////		
	//	}
	//	catch(IOException e){
	//		e.printStackTrace();
	//	}

}
