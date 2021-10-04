using System;

namespace BubbleSort
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] arr = {64, 34, 25, 12, 22, 11, 90};
            int n = arr.Length;
            int temp = 0;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n-i-1; j++)
                {
                    if(arr[j] > arr[j+1]){
                        temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                    }
                }
            }
            Console.WriteLine("Sorted array");
            for(int i = 0; i < n; i++)
            {
                Console.Write(arr[i] + " ");
            }
        }
    }
}