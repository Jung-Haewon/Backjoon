using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _11050
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] num = Console.ReadLine().Split().Select(Int32.Parse).ToArray();
            int ans = 1;

            for(int i = 0; i < num[1]; i++)
            {
                ans *= num[0];
                num[0]--;
            }

            for (int i = 0; i < num[1]; i++)
            {
                ans /= (i + 1);
            }

            Console.WriteLine(ans);
        }
    }
}
