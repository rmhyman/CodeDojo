package firstNonReapeatChar;

import java.util.HashMap;

public class firstNonRepeated {
	
	public static Character firstNonRepeated(String str){
		HashMap<Character, Integer> charHash = new HashMap<Character, Integer>();
		
		int length;
		Character c;
		
		//Scan str, building hash table
		for(int i = 0; i < str.length(); i++){
			c = str.charAt(i);
			//checking to see if it's in the  hashtable if it is add 1
			if(charHash.containsKey(c)){
				//if it's in the hash table ALREADY go to that value using the c(key) and add 1 
				charHash.put(c, charHash.get(c) + 1);
			}else{
				charHash.put(c, 1);
			}
		}
		//Search hash table again to see which char on showed up ONCE
		for(int i = 0; i < str.length(); i++){
			c = str.charAt(i);
			if(charHash.get(c) == 1){
				return c;
			}
		}
		return null;		
	}

	public static Character duplicateChar(String str){
		HashMap<Character, Integer> charHash = new HashMap<Character, Integer>();
		
		Character c;
		
		for(int i = 0; i < str.length(); i++){
			c = str.charAt(i);
			if(charHash.containsKey(c)){
				charHash.put(c, charHash.get(c) + 1);
			}else{
				charHash.put(c, 1);
			}
		}
		for(int i = 0; i < str.length(); i++){
			c = str.charAt(i);
			if(charHash.get(c) > 1){
				return c;
			}
		}
		return null;
	}
	
	public static 
	
	public static void main (String[] args){
		String str = "themanllivveeiinthehouuosssehisnamewwasD";
		
		System.out.println("First Non repeated char: " + firstNonRepeated(str));
		System.out.println("First Duplicate char: " + duplicateChar(str));
	}
}
