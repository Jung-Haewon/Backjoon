using System;

namespace _2720
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] coin = { 25, 10, 5, 1 };
            int n = Int32.Parse(Console.ReadLine());
            for(int i = 0; i < n; i++)
            {
                string ans = "";
                int tmp = Int32.Parse(Console.ReadLine());

                foreach(int j in coin)
                {
                    ans += tmp / j + " ";
                    tmp %= j;
                }
                Console.WriteLine(ans);
            }
        }
    }
}
