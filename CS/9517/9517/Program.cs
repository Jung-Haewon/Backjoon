using System;

namespace _9517
{
    class Program
    {
        static void Main(string[] args)
        {
            int k, n;
            int nowTime = 0;
            int endTime = 210;

            k = Int32.Parse(Console.ReadLine());
            n = Int32.Parse(Console.ReadLine());

            while (true)
            {
                string[] tmp = Console.ReadLine().Split();
                nowTime += Int32.Parse(tmp[0]);

                if (nowTime > endTime)
                    break;

                if (tmp[1].CompareTo("T") == 0) {
                    if (k == 8)
                        k = 1;
                    else
                        k++;
                }
            }

            Console.Write(k);
        }
    }
}
