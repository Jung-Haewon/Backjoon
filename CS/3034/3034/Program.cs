using System;

namespace _3034
{
    class Program
    {
        static void Main(string[] args)
        {
            int n, w, h;
            string[] condition = Console.ReadLine().Split();
            n = Int32.Parse(condition[0]);
            w = Int32.Parse(condition[1]);
            h = Int32.Parse(condition[2]);

            int limit = w*w + h*h;

            for(int i = 0; i < n; i++)
            {
                int tmp = (int)Math.Pow(Double.Parse(Console.ReadLine()), 2);
                Console.WriteLine(tmp <= limit? "DA": "NE");
            }
        }
    }
}
