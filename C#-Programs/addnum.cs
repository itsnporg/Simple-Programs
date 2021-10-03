using System;
class AddTwoNumbers {
    static void Main() {
        try{
            //declaring two variables
            int a = 0;
            int b = 0;
            
            //input numbers
            Console.Write("Enter first number: ");
            a = Convert.ToInt32(Console.ReadLine());
            Console.Write("Enter second number: ");
            b = Convert.ToInt32(Console.ReadLine());            
            
            //calculating the sum
            int sum = a+b;
            
            Console.WriteLine("The addition of " + a + " and " + b + " is = " + sum + ". Happy Hacktober!");
        }
        catch(Exception ex){
            Console.WriteLine("Error: " + ex.ToString());
        }
    }
}
