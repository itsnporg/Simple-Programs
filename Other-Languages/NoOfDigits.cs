using System;

class RecExercise5
    {
        static void Main(string[] args)
        {
            
        Console.Write("\n\n Recursion : Count the number of digits in a number :\n");
        Console.Write("---------------------------------------------------------\n");
        Console.Write(" Input any number : ");
        int num = Convert.ToInt32(Console.ReadLine());           
        Console.Write("\n The number {0} contains number of digits : {1} ",num,getDigits(num, 0));
        Console.ReadLine();
        }

public static int getDigits(int n1, int nodigits)
    {
    if (n1 == 0)
        return nodigits;

    return getDigits(n1 / 10, ++nodigits);
    }
}
