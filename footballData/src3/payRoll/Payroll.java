/*Design a Payroll class  with the following fields:

• name : a String  containing the employee's name 
• idNumber: an int  representing the employee's ID number
• rate: a double  containing the employee's hourly pay rate
• hours: an int  representing the number of hours this employee has worked

The class  should also have the following methods :

• Constructor : takes the employee's name  and ID number as arguments 
• Accessors: allow access to all of the fields of the Payroll class 
• Mutators: let the user assign  values  to the fields of the Payroll class 
• grossPay: returns the employee's gross pay, which is calculated as the number of 
hours worked times the hourly pay rate.

Write another program  that demonstrates the class  by creating a Payroll object , then
asking the user to enter the data for an employee in the order: name , ID number, rate, hours.
The program  should then print out a statement  in the following format (for example, if
you had an employee named  Chris Jacobsen with ID number 11111, who works for 5 hours at 
$10/hr):

Chris Jacobsen, employee number 11111, made $50.00 in gross pay.

Using text forming so that the gross pay is rounded to two decimal places. 

My Code:*/




/**
 * @(#)Text2.java
 *
 *
 * @author 
 * @version 1.00 2016/1/28
 */

package payRoll;
import java.util.Scanner;
import java.text.DecimalFormat;
import java.text.NumberFormat;

     public class Payroll
     {
        private String EmployeeName;
        private int IDnumber;
        private double HourlyPayRate;
        private double TotalHoursWorked;
        private double TotalGrossPay;

        public Payroll(String Name, int ID, double HourlyRate, double HoursWorked)
        {
            EmployeeName = Name;
            IDnumber = ID;
            HourlyPayRate = HourlyRate;
            TotalHoursWorked = HoursWorked;
        }
        public String getEmployeeName()
        {
            return EmployeeName;
        }
        public int getIDnumber()
        {
            return IDnumber;
        }
        public double setHourlyPayRate()
        {
            return HourlyPayRate;
        }
        public double getHourlyPayRate()
        {
            return HourlyPayRate;
        }
        public double setTotalHoursWorked()
        {
            return TotalHoursWorked;
        }
        public double getTotalHoursWorked(double HoursWorked)
        {
            return TotalHoursWorked;
        }
        public double setTotalGrossPay()
        {
            return TotalGrossPay;
        }
        public double getTotalGrossPay(double HourlyRate, double HoursWorked)
        {
            return HourlyPayRate * TotalHoursWorked;
        }


   public static void main(String[] args){
            String EmployeeName;
            int IDnumber;
            double TotalHoursWorked;
            double HourlyPayRate;
            double TotalGrossPay;
            
            NumberFormat formatter = new DecimalFormat("#0.00");

            Scanner keyboard = new Scanner(System.in);

            System.out.print("Enter employee's name:");
            EmployeeName = keyboard.nextLine();

            System.out.print("Enter employee's ID number:" );
            IDnumber = keyboard.nextInt();

            System.out.print("Enter hourly rate:");
            HourlyPayRate = keyboard.nextDouble();

            System.out.print("Enter number of hours worked:");
            TotalHoursWorked = keyboard.nextDouble();

            Payroll pay = new Payroll(EmployeeName, IDnumber, HourlyPayRate, TotalHoursWorked);

            System.out.print(EmployeeName + ", " + "employee number " + IDnumber + ", made $" + 
            		formatter.format(pay.getTotalGrossPay(HourlyPayRate, TotalHoursWorked)) + " in gross pay.");
       }
  }



/*Output:
Enter employee's name:Chris Jacobsen
Enter employee's ID number:11111
Enter hourly rate:10
Enter number of hours worked:5
Chris Jacobsen, employee number 11111, made $0.0 in gross pay.



Expected Output:
Enter employee's name:Chris Jacobsen
Enter employee's ID number:11111
Enter hourly rate:10
Enter number of hours worked:5
Chris Jacobsen, employee number 11111, made $50.0 in gross pay.*/