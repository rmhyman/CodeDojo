package holesText;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;

import turboSort.turboSort;

public class HolesText {
	
	 public HolesText(String file) throws FileNotFoundException{
			
			Scanner sc = new Scanner(new File(file));
			String text;
			String oneAlpha = "AabDdegOoPpQqR";
			char B = 'B';
			
			text = sc.nextLine();
			
			for(int i = 0; i < text.length(); i++){
				for(int j = 0; j < oneAlpha.length(); j++){
					if(text.charAt(i) == oneAlpha.charAt(j)){
						System.out.println(text.charAt(i) + " == " + oneAlpha.charAt(j));
					}
				}
					
				//System.out.println(text.charAt(i));
			}
			
			
			/*while(sc.hasNext()){
				text = sc.nextLine();
			}*/
	 }

	 public static void main(String[] args) throws IOException{
			// TODO Auto-generated method stub
			
				Scanner sc = new Scanner(System.in);
				System.out.println("Enter input file name: ");
				String file = sc.nextLine();
				HolesText data = new HolesText(file);
			}
}
