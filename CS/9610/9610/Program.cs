using System;
using static System.Console;

namespace _9610
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] quadrant = new int[5];
            int n = Int32.Parse(ReadLine());
            for (int i = 0; i < n; i++)
            {
                string[] tmp = ReadLine().Split();
                int x = Int32.Parse(tmp[0]);
                int y = Int32.Parse(tmp[1]);

                if (x == 0 || y == 0)
                    quadrant[4]++;
                else
                {
                    if(x > 0)
                        if (y > 0) quadrant[0]++; else quadrant[3]++;
                    else
                        if (y > 0) quadrant[1]++; else quadrant[2]++;
                }
            }

            for(int i = 1; i <5; i++)
                WriteLine("Q{0}: {1}", i, quadrant[i - 1]);
            WriteLine("AXIS: {0}", quadrant[4]);
        }
    }
}
