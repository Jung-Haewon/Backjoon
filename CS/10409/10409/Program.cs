using System;
using System.Linq;

namespace _10409
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = Int32.Parse(Console.ReadLine().Split()[1]);
            int now = 0, cnt = 0;
            int[] task = Console.ReadLine().Split().Select(Int32.Parse).ToArray();

            foreach(int time in task)
            {
                now += time;
                if (now > t) break;
                cnt++;
            }

            Console.WriteLine(cnt);
        }
    }
}
