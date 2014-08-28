/*Chef wrote some text on a piece of paper and now he wants to know how many holes are in the text. 
 * What is a hole? If you think of the paper as the plane and a letter as a curve on the plane, then 
 * each letter divides the plane into regions. For example letters "A", "D", "O", "P", "R" divide the 
 * plane into two regions so we say these letters each have one hole. Similarly, letter "B" has two 
 * holes and letters such as "C", "E", "F", "K" have no holes. We say that the number of holes in the 
 * text is equal to the total number of holes in the letters of the text. Help Chef to determine how 
 * many holes are in the text.
 * 
 * Input : The first line contains a single integer T <= 40, the number of test cases. T test cases 
 * follow. The only line of each test case contains a non-empty text composed only of uppercase letters 
 * of English alphabet. The length of the text is less then 100. There are no any spaces in the input.
 * 
 * Output : For each test case, output a single line containing the number of holes in the corresponding text.*/

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
			int points = 0;		
			int numTest;
			
			
			//text = sc.next();
			while(sc.hasNext()){
				numTest = sc.nextInt();
				while(numTest != 0){
					text = sc.nextLine().trim();
					if(text.length() == 0)
						continue;
					for(int i = 0; i < text.length(); i++){
						for(int j = 0; j < oneAlpha.length(); j++){
							if(text.charAt(i) == oneAlpha.charAt(j)){
								//System.out.println(text.charAt(i) + " == " + oneAlpha.charAt(j));
								points++;
								break;
							}
							if(text.charAt(i) == 'B'){
								//System.out.println(text.charAt(i) + " == B");
								points += 2;
								break;
							}
						}
					}
					System.out.println(text + " points: " + points);
					numTest--;
					points = 0;
				}	
			}
	 }

	 public static void main(String[] args) throws IOException{
			// TODO Auto-generated method stub
			
				Scanner sc = new Scanner(System.in);
				System.out.println("Enter input file name: ");
				String file = sc.nextLine();
				HolesText data = new HolesText(file);
			}
}
