/*In weather.dat you’ll find daily weather data for Morristown, NJ for June 2002. 
 *Download this text file, then write a program to output the day number (column one)
 *with the smallest temperature spread (the maximum temperature is the second column, t
 *he minimum the third column).
 */

package weatherData;

import java.util.Arrays;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.lang.reflect.Array;
import java.util.Scanner;


public class weatherData {

	private int day;
	private int minTemp;
	private int maxTemp;
	public int recordMinTemp = 150;
	
	//getter functions
	public int getDay(){
		return day;
	}
	public int getMinTemp(){
		return minTemp;
	}
	public int getMaxTemp(){
		return maxTemp;
	}
	
	//setter functions
	public void setDay(int d ){
		day = d;
	}
	public void setMinTemp(int min){
		minTemp = min;
	}
	public void setMaxTemp(int max){
		maxTemp = max;
	}
	
	public int tempSpread(int max, int min){
		
		return max - min;
	}
	
public weatherData(String file) throws FileNotFoundException{
		
		Scanner sc = new Scanner(new File(file));
		int count = 0;
		int[] tempDiff = new int[30];
		//want to grab the first line I don't need it
		String firstLine; 
		firstLine = sc.nextLine();
		
		//while there is a next line to read from
		while(sc.hasNextLine()){
			//trim of any whitespace 
			String line = sc.nextLine().trim();
			
			if(line.length() == 0)
				continue;	
			
			String delims = " ";
			String[] tokens = line.split(delims);
			
			String delims2 = "[ *]";
			String[] tokens2 = line.split(delims2);
			
			if(line.contains("mo")){
				break;
			}
			if(!line.contains("*")){
				int day = stringtoInt(tokens[0]);
			}
			else{
				int min = stringtoInt(tokens2[6]);
				int max = stringtoInt(tokens2[2]);
				}
			
			setDay(stringtoInt(tokens[0]));
			setMinTemp(stringtoInt(tokens2[6]));
			setMaxTemp(stringtoInt(tokens2[2]));
			
			tempDiff[count] = tempSpread(getMaxTemp(), getMinTemp());
			System.out.println("tempDiff[" + count + "]: " + tempDiff[count]);
			count++;		
			}	
		//sort the array of tempSpread and return the smallest spread
		for(int i = 0; i < count; i++){
			if(tempDiff[i] < recordMinTemp){
				recordMinTemp = tempDiff[i];
				setDay(i);
			}
		}
		System.out.println("Date with smallest temperature spread is June " + getDay() + ", 2002, with a temperature spread of: " + recordMinTemp);
		
	}
		

int stringtoInt(String s){
	int toInt = Integer.parseInt(s);
	return toInt;
}
	
	public static void main (String[] args)
			throws IOException{
				Scanner sc = new Scanner(System.in);
				System.out.println("Enter data input file name: ");
				String file = sc.nextLine();
				weatherData data = new weatherData(file);
				//graphAdjList graph = new graphAdjList(file);
				
			}
}

