import java.util.Scanner;


public class TwentyOneSticks {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int numberOfSticks = 21;
		int takeSticks = 0;
		
		Scanner input = new Scanner(System.in);
		Scanner take = new Scanner(System.in);
		
		System.out.println("Would you like to go first? (Y/y)");
		String goFirst = input.nextLine();
		
		while(numberOfSticks > 0){
			//Two ways to compare strings in Java
			//Option if Player 1 goes first
			if(goFirst == "Y" || goFirst.equals("y")){
				System.out.println("Remaing Sticks: " + numberOfSticks);
				System.out.println("How many sticks? (1 or 2)");
				takeSticks = take.nextInt();
				
				//quick Check to see if user inputed the correct values
				if (takeSticks >= 2)
					takeSticks = 2;
				else if (takeSticks <= 1)
					takeSticks = 1;
				
				System.out.println("Player 1 takes " + takeSticks + " sticks.");
				
				numberOfSticks -= takeSticks;
				
				//Need to check to see if the there are any sticks left if not Game over
				if(numberOfSticks <= 0)
					System.out.println("You lose!");
				
				//Else have Computer decide on how many sticks to chose
				//if taking two leaves a mutiple of 3 or if taking two sticks makes
				//it lose the game only take 1. So after checking these two conditions
				//it will take either one stick on 2.
				else{
					
					if((numberOfSticks - 2) % 3 == 0 || numberOfSticks - 2 == 0)
						takeSticks = 1;
					else 
						takeSticks = 2;
					
					System.out.println("Computer takes: " + takeSticks);
					numberOfSticks -= takeSticks;
					
					if(numberOfSticks <= 0)
						System.out.println("You win!");
				}
			}
			else{
				
				if((numberOfSticks - 2) % 3 == 0 || numberOfSticks - 2 == 0)
					takeSticks = 1;
				else 
					takeSticks = 2;
				
				System.out.println("Computer takes: " + takeSticks);
				numberOfSticks -= takeSticks;
				
				if(numberOfSticks <= 0)
					System.out.println("You win!");	
				else{
					System.out.println("Remaing Sticks: " + numberOfSticks);
					System.out.println("How many sticks? (1 or 2)");
					takeSticks = take.nextInt();
					
					//quick Check to see if user inputed the correct values
					if (takeSticks >= 2)
						takeSticks = 2;
					else if (takeSticks <= 1)
						takeSticks = 1;
					
					System.out.println("Player 1 takes " + takeSticks + " sticks.");
					
					numberOfSticks -= takeSticks;
					
					//Need to check to see if the there are any sticks left if not Game over
					if(numberOfSticks <= 0)
						System.out.println("You lose!");
				}
			}
		}
	}

}
