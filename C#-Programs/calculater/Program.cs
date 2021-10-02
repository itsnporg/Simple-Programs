using System;

namespace calculater
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("========================================================Console Calculater========================================================");
            Console.WriteLine("Enter Operation you like to execute");
            Console.WriteLine("1.) Addition");
            Console.WriteLine("2.) Subtraction");
            Console.WriteLine("2.) Multiplication");
            Console.WriteLine("2.) Division");
            int option = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Add First Number");
            int a = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Add Secind Number");
            int b = Convert.ToInt32(Console.ReadLine());
            int result = 0;
            switch (option)
            {
                case 1:
                    result = Addition(a, b);
                    break;
                case 2:
                    result = Subtraction(a, b);
                    break;
                case 3:
                    result = Multiplication(a, b);
                    break;
                case 4:
                    result = Division(a, b);
                    break;
                default:
                    Console.WriteLine("Sorry ! Something went wrong");
                    break;
            }
            Console.WriteLine("Your Operation result is " + result);
            Console.WriteLine("========================================================Console Calculater========================================================");
        }

        public static int Addition(int a, int b)
        {
            int result = a + b;
            return result;
        }

        public static int Subtraction(int a, int b)
        {
            int result = a - b;
            return result;
        }

        public static int Multiplication(int a, int b)
        {
            int result = a * b;
            return result;
        }

        public static int Division(int a, int b)
        {
            int result = a / b;
            return result;
        }
    }
}
