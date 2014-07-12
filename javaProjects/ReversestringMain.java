package reverseString;


import java.lang.StringBuilder;
import java.util.Scanner;

public class ReversestringMain {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
			
			Scanner scan = new Scanner(System.in);
			String myString = "";
			
			System.out.println("Enter a word.");
			myString = scan.nextLine();
			System.out.println("Your word: " + myString);
			
			//Create temp char array to hold the characters from myString
			//Then use the temp array to place in reverse in the reverseChar array
			char[] tempChar = new char[myString.length()];
			char[] reverseChar = new char[myString.length()];
			
			for(int i = 0; i < myString.length(); i++){
				
				tempChar[i] = myString.charAt(i);
				
			}
			
			for(int j = 0; j < myString.length(); j++){
				
				reverseChar[j] = myString.charAt(myString.length() - 1- j);
			}
			
			String finString = new String(reverseChar);
			System.out.println("Reverse order: " + finString);
			
			//*************OR YOU CAN USE STRINGBUILDER CLASS*****************//
			
			String myString2 = "";
			
			System.out.println("Enter another word.");
			myString2 = scan.nextLine();
			System.out.println("Your string: " + myString2);
			
			StringBuilder reverseString2 = new StringBuilder(myString2);
			reverseString2.reverse();
			
			System.out.println("Reversed String2: " + reverseString2);

	}

}
