import java.util.ArrayList;
import java.util.ListIterator;
import java.util.Vector;
import java.util.Scanner;
import java.lang.StringBuilder;

import javax.swing.text.html.HTMLDocument.Iterator;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//Vector examples
		//Initial size is 5, increment is 2
		/*Vector v = new Vector(5, 2);
		System.out.println("Size of vector: " + v.size());
		System.out.println("The initial capacity: " + v.capacity());
		
		v.add(5);*/
		
		//To declare a Vector of size 10 and its space 
		//will increase by 2 when more then 10 elements are added.
		Vector<String> vString = new Vector<String>(10, 2);

		/*vString.add("test");
		System.out.println("Value is: " + vString.get(0));
	
		//Or this way
		String myTest ="my Test";	
		vString.add(myTest);	
		System.out.println("Value is: " + vString.get(1));
		
		System.out.println("The number of elements in vector: " + vString.size());*/
		
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
		
		/*for(int i = 0; i <= vString.size(); i++ ){
			
			System.out.println("Enter a word, type Exit to stop.");
			
			myString = scan.nextLine();
			
			if(myString.equals("Exit"))
				break;
			vString.add(myString);
		}
		
		for(int i = 0; i < vString.size(); i++){
			
			System.out.println("Your input: " + vString.get(i) );
		}
		*/
		
		
		//use stringBuilder!!!!
		
		ArrayList<String> stringL = new ArrayList <String>();
		
		stringL.add("Item");
		
		//stringL.add(new Integer(2));  Can only add string
		
		String myItem = "";
		
		for(int i = 0; i < stringL.size(); i++){
			
			System.out.println("Enter your item type Done to stop.");
			myItem = scan.nextLine();
			
			if(myItem.equals("Done"	))
				break;
			stringL.add(myItem);
		}
		
		Iterator itr = (Iterator) stringL.iterator();
		ListIterator itrList = (ListIterator) stringL.iterator();
		
		while(itrList.hasNext()){
			System.out.println("Item entered: " + itrList.next());
		}
	}
}

