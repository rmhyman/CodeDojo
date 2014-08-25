/*The file football.dat contains the results from the English Premier League for 2001/2. 
 * The columns labeled ‘F’ and ‘A’ contain the total number of goals scored for and 
 * against each team in that season (so Arsenal scored 79 goals against opponents, and had 
 * 36 goals scored against them). Write a program to print the name of the team with the 
 * smallest difference in ‘for’ and ‘against’ goals.
 */
package footballData;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.HashMap;
import java.util.Scanner;



public class footballLeague {
	
	private int goalFor;
	private int goalAgainst;
	
	public int getGoalFor(){
		return goalFor;
	}
	
	public int getGoalAgainst(){
		return goalAgainst;
	}
	
	public void setGoalFor(int gFor){
		goalFor = gFor;
	}
	
	public void setGoalAgainst(int gAgainst){
		goalAgainst =  gAgainst;
	}
	
	public int scoreDifference(int gFor, int gAgainst){
		return gFor - gAgainst;
	}
	
    public footballLeague(String file) throws FileNotFoundException{
		
		Scanner sc = new Scanner(new File(file));
		String firstLine;
		firstLine = sc.nextLine();
		Integer maxDiff = 100;
		String[] tokens = null;
		int count = 0;
		int[] scoreDiff = new int [100000];
		
		HashMap<Integer, String> map = new HashMap<Integer, String>();
		
		while(sc.hasNextLine()){
			String line = sc.nextLine().trim();
			if(line.length() == 0){
				continue;
			}
			tokens = line.split("\\s+ ");
			if(tokens[0].matches(".*[-].*"))
				continue;
			else{
				setGoalFor(stringtoInt(tokens[5]));
				setGoalAgainst(stringtoInt(tokens[7]));
				scoreDiff[count] = Math.abs(scoreDifference(getGoalFor(), getGoalAgainst()));
				map.put(scoreDiff[count], tokens[0]);
				System.out.println(scoreDiff[count]);
				count++;
				
			}		
		}
		for(int i = 0; i < count; i++){
			if(scoreDiff[i] < maxDiff){
				maxDiff = scoreDiff[i];
			}
		}
		String team = map.get(maxDiff);
		System.out.println("The team with the smallest difference in ‘for’ and ‘against’ goals: " + team + "with difference of: " + maxDiff);
	}
	
	int stringtoInt(String s){
		int toInt = Integer.parseInt(s);
		return toInt;
	}
	public static void main (String[] args)
		throws IOException{
			Scanner sc = new Scanner(System.in);
			System.out.println("Enter league input file name: ");
			String file = sc.nextLine();
			footballLeague data = new footballLeague(file);
		}
}
