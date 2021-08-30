using System;
using System.Linq;

namespace _5073
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] result = { "Equilateral", "Isosceles", "Scalene", "Invalid" };
            int ret;
            while (true)
            {
                int[] arr = Console.ReadLine().Split().Select(Int32.Parse).ToArray();
                Array.Sort(arr);

                if (arr[0] + arr[1] + arr[2] == 0) break;

                if (arr[0] + arr[1] <= arr[2]) ret = 3;
                else if (arr[0] == arr[1] && arr[1] == arr[2]) ret = 0;
                else if (arr[0] == arr[1] || arr[1] == arr[2]) ret = 1;
                else ret = 2;

                Console.WriteLine(result[ret]);
            }
        }
    }
}
