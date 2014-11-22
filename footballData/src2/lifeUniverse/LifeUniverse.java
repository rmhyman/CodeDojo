package lifeUniverse;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Scanner;



public class LifeUniverse {

	public LifeUniverse(String file) throws FileNotFoundException{
			
			Scanner sc = new Scanner(new File(file));
			Integer nInt;
			File file1 = new File("C:\\Users\\Demetrius\\Documents\\output.txt");
			// if file doesnt exists, then create it
			if (!file1.exists()) {
				try {
					file1.createNewFile();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			PrintWriter pw = new PrintWriter(file1);
			nInt = sc.nextInt();
			OutputFile(nInt.toString(), pw);
			
			while(sc.hasNext()){
				nInt = sc.nextInt();
				if(nInt != 42){
					OutputFile(nInt.toString(), pw);
				}
				else{
					pw.close();
					break;
					}
				}
	}
	
	public void OutputFile(String output, PrintWriter pw){
		
		pw.println(output);
		//pw.append(output);
		 //Don't need to close after pw.close();
		
		
		System.out.println("Done");

	}
	
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		
			Scanner sc = new Scanner(System.in);
			System.out.println("Enter input file name: ");
			String file = sc.nextLine();
			LifeUniverse data = new LifeUniverse(file);
			
	}
}
