
/**
 * @author demetrius
 *
 */

import java.util.Random;
import java.util.Scanner;

public class GuessingGame {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Random rand = new Random();
		int randomNumber;
		int numberofTries = 0;
		int guess = 0;
		boolean wrongGuess = false;
		
		randomNumber = rand.nextInt(1000);
		
		while(wrongGuess == false){
			
			System.out.println("Enter your guess between 1 and 1000.");
			Scanner input = new Scanner(System.in);
			numberofTries++;
		
			wrongGuess = processUserGuess(randomNumber,input.nextInt());
		
		}
	}

	public static boolean processUserGuess(int randomNumber, int input) {
		int guess = input;
		boolean wrongGuess = false;

		if (guess == randomNumber){
			wrongGuess = true;
		
		}
		else if (guess < randomNumber){
			System.out.println("Guess is too Low");

		}
		else 
			System.out.println("Guess is too High");
		return wrongGuess;
	}
}
