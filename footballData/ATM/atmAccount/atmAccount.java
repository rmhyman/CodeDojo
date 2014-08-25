package atmAccount;

import java.util.Scanner;

public class atmAccount {
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Integer withdraw;
		Double balance;
		double serviceFee = 0.50;
		System.out.println("Pleae enter the amount you wish to withdraw: ");
		Scanner sc = new Scanner(System.in);
		withdraw = sc.nextInt();
		System.out.println("Please enter your account balance: ");
		balance = sc.nextDouble();
		
		if((withdraw % 5) == 0){
			if(balance < withdraw){
				System.out.println("Not enough money in account. Goodbye.");
			}
			else if(balance <= 0){
				String s = String.format(("%.2f"), balance); 
				System.out.println(s);
			}else if(balance > 2000){
				System.out.println("The limit for withdraws is $2000. Sorry.");
			}else{	
			System.out.println("One moment please...");
			balance = balance - withdraw - serviceFee;
			String s = String.format(("%.2f"), balance); 
			System.out.println("Your balance: " + s);
			}
		}
		else
			System.out.println(balance);
	}

}
