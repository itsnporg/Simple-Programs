//C# program to convert a decimal number into an octal number.

using System;

class Program
{
    static void Main(string[] args)
    {
        int decNum = 0;
        int octNum = 0;
        string temp = "";
        

        Console.Write("Enter a Decimal Number :");
        decNum = int.Parse(Console.ReadLine());


        while (decNum != 0)
        {
            temp += decNum % 8;
            decNum = decNum / 8;
        }

        for (int i = temp.Length - 1; i >= 0; i--)
        {
            octNum = octNum * 10 + temp[i] - 0x30;
        }

        Console.WriteLine("Octal Number is " + octNum);
    }
}