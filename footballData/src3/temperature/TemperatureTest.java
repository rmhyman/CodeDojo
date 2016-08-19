/*Write a Temperature class  that will hold a temperature in Fahrenheit and provide methods  
 * to get the temperature in Fahrenheit, Celsius, and Kelvin. The class  should have the following field:
 * • ftemp: a double  that holds a Fahrenheit temperature.
 * The class  should have the following methods :
 * • Constructor : The constructor  accepts a Fahrenheit temperature (as a double ) and stores  it in the ftemp field.
 * • setFahrenheit: The set Fahrenheit method  accepts a Fahrenheit temperature (as a double ) and stores  it in the ftemp field.
 * • getFahrenheit: Returns the value  of the ftemp field as a Fahrenheit temperature (no conversion  required)
 * • getCelsius: Returns the value  of the ftemp field converted to Celsius. Use the following formula to convert to Celsius:
 * Celsius = (5/9) * (Fahrenheit - 32)
 * • getKelvin: Returns the value  of the ftemp field converted to Kelvin. Use the following formula to convert to Kelvin:
 * Kelvin = ((5/9) * (Fahrenheit - 32)) + 273
 
 * Demonstrate the Temperature class  by writing a separate program  that asks the user for a 
 * Fahrenheit temperature. The program  should create an instance of the Temperature class ,
 * with the value  entered by the user passed to the constructor . The program  should then
 * call the object 's methods  to display the temperature in the following format (for example, if the temperature in Fahrenheit was -40):
 
 * The temperature in Fahrenheit is -40.0
 * The temperature in Celsius is -40.0
 * The temperature in Kelvin is 233.0 

My Code:

*/
package temperature;
import java.util.Scanner;
import java.text.DecimalFormat;
 
public class TemperatureTest {
	
	private double ftemp;
	
	public TemperatureTest(double Fahrenheit){
		ftemp = Fahrenheit;
	}
	public double getFahrenheit(){
		return ftemp;
	}
	public void setFahrenheit(double Fahrenheit){
		ftemp = Fahrenheit;
	}
	public double getCelsius(){
		return ((double)5/9*(ftemp-32));
	}
	public double getKelvin(){
	    return (((double)5/9*(ftemp-32))+273);
	}

 
 public static void main(String[] args) {
 
	 Scanner keyboard = new Scanner(System.in);
	 System.out.print("Enter Fahrenheit temperature: ");
	 double temp = keyboard.nextDouble(); 
	 
	 TemperatureTest finalTemp = new TemperatureTest(temp);
	 System.out.println("The temperature in Fahrenheit is " + finalTemp.getFahrenheit());
	 System.out.println("The temperature in Celsius is " + finalTemp.getCelsius());
	 System.out.println("The temperature in Kelvin is " + finalTemp.getKelvin());
	 }

}
//Error when trying to run program with compile errors: Error: Could not find or load main class TemperatureTest
