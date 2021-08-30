using System;

namespace _2863
{
    class Program
    {
        static void Main(string[] args)
        {
            double a, b, c, d;
            var x = Console.ReadLine().Split();
            var y = Console.ReadLine().Split();
            a = double.Parse(x[0]);
            b = double.Parse(x[1]);
            c = double.Parse(y[0]);
            d = double.Parse(y[1]);

            double[] result = {
                a/c + b/d,
                c/d + a/b,
                d/b + c/a,
                b/a + d/c
            };

            double max = result[0];
            int ans = 0;

            for(int i = 1; i < 4; i++)
            {
                if( result[i] > max)
                {
                    max = result[i];
                    ans = i;
                }
            }

            Console.WriteLine(ans);
        }
    }
}
