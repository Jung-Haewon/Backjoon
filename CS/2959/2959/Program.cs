using System;
using System.Linq;

namespace _2959
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] line = Console.ReadLine().Split().Select(Int32.Parse).ToArray();
            Array.Sort(line);
            Console.WriteLine(line[0] * line[2]);
        }
    }
}
