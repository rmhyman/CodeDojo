import java.lang.String;
import java.util.Scanner;
import java.lang.StringBuilder;

public class PiglatinMain {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		String vowels = "aeiouy";
		String word = "";
		
		System.out.println("Enter your word.");
		Scanner scan = new Scanner(System.in);
		word = scan.nextLine();
		System.out.println("Your word: " + word);
		boolean complete = false;
		
		int length = 0;
		
		length = word.length();
		
		for(int i = 0; i < 6; i++){
			if(vowels.charAt(i) != word.charAt(0))
				continue;
			else{
				//need for loop here to check for second vowel like: aim, you, yet, out, etc.
				for(int j = 0; j < 6; j++){
					if(vowels.charAt(j) != word.charAt(1))
						continue;
					else{
						System.out.println("Your Word: " + word + " in Piglatin: "  + word +"say.");
						complete = true;
					}
				}
				if(complete)
					break;
				if(length <= 2){//For small words like: a, it, if, I, etc.
					System.out.println("Your Word: " + word + " in Piglatin: "  + word +"way.");
					complete = true;
				}
				else{
						//for cases like about or another
						String constChars = word.substring(0,1);
						StringBuilder pigLatin = new StringBuilder (word);
						pigLatin.delete(0,1);
					
						//System.out.println("constChars: " + constChars + " pigLatin: " + pigLatin);
						System.out.println("Your Word: " + word + " in Piglatin: " + pigLatin + " - " + constChars +"hay.");
						complete = true;
					}
				}
			}
		for(int i = 0; i < 6; i++){
			if(vowels.charAt(i) == word.charAt(0))
				System.out.println("Niggas are Poo");
			else {
				for(int j = 1; j < 6; j++){
					if (complete)
						break;
					if(vowels.charAt(j) == word.charAt(1)){
						String constChars = word.substring(0,1);
						StringBuilder pigLatin = new StringBuilder(word);
						pigLatin.delete(0, 1);
						
						System.out.println("Your Word: " + word + " in Piglatin: " + pigLatin + " - " + constChars +"ay.");
						complete = true;
					}
					else{
						String constChars = word.substring(0,2);
						StringBuilder pigLatin = new StringBuilder(word);
						pigLatin.delete(0, 2);
						
						System.out.println("Your Word: " + word + " in Piglatin: " + pigLatin + " - " + constChars +"ay.");
						complete = true;
						break;
					}	
				}
			}
			break;
		}
	}
}
		
			/*	//for(int j = 0; j < 6; j++){
					if(vowels.charAt(1) == word.charAt(1)){
						//System.out.println("vowel at: " + vowels.charAt(j) + " == word at: " + word.charAt(1));
						//String constChars = word.substring(0,2);
						//StringBuilder pigLatin = new StringBuilder (word);
						//pigLatin.delete(0,2);
						
						//System.out.println("constChars: " + constChars + " pigLatin: " + pigLatin);
						System.out.println("Your Word: " + word + " in Piglatin: " + word + " - ay.");
						complete = true;
					}
					else{
						constChars = word.substring(0,1);
						pigLatin = new StringBuilder (word);
						pigLatin.delete(0,1);
						
						System.out.println("constChars: " + constChars + " pigLatin: " + pigLatin);
						System.out.println("Your Word: " + word + " in Piglatin: " + pigLatin + " - " + constChars +"hay.");
						complete = true;
						}
					//break;
					//}
				//}
			else{//for word cases like switch or other constant clusters
				String constChars = word.substring(0,2);
				StringBuilder pigLatin = new StringBuilder (word);
				pigLatin.delete(0,2);
				
				//System.out.println("constChars: " + constChars + " pigLatin: " + pigLatin);
				System.out.println("Your Word: " + word + " in Piglatin: " + pigLatin + " - " + constChars +"ay.");
				complete = true;
				}
			//break;
			//}
			if(!complete){
				for(int i = 0; i < 6; i++){
					if(vowels.charAt(i) == word.charAt(1)){
						System.out.println("vowel at: " + vowels.charAt(i) + " == word at: " + word.charAt(1));
						char constChar = word.charAt(0);
						StringBuilder pigLatin = new StringBuilder (word);
						pigLatin.deleteCharAt(0);
						System.out.println("Your Word: " + word + " in Piglatin: " + pigLatin + "-" + constChar + "ay.");
						}
					else{
						//System.out.println("vowel at: " + vowels.charAt(i) + " != word at: " + word.charAt(0));
						}
				}*/

