using System;
using System.Linq;

namespace _2783
{
    class Program
    {
        static void Main(string[] args)
        {
            double[] xy = Console.ReadLine().Split().Select(Double.Parse).ToArray();
            double ans = xy[0] / xy[1] * 1000;
            int n = Int32.Parse(Console.ReadLine());

            for(int i = 0; i < n; i++)
            {
                double[] xnyn = Console.ReadLine().Split().Select(Double.Parse).ToArray();
                double tmp = xnyn[0] / xnyn[1] * 1000;
                if (tmp < ans) ans = tmp;
            }

            Console.WriteLine("{0:.00}", ans);
        }
    }
}
