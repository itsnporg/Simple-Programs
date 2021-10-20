using System;
 
namespace Sort_Array_Des
{
    public class Program
    {
        public static void Main(string[] args)
        {
            int[] num= {22,50,11, 2, 49};
            Array.Sort(num);
            Array.Reverse(num);
            for(int i=0; i<num.Length; i++)
            {
                Console.Write(num[i] + " ");
            }
        }
    }
}