using System;

namespace _5717
{
    class Program
    {
        static void Main(string[] args)
        {
            int m, f;
            while (true)
            {
                string[] tmp = Console.ReadLine().Split();
                m = Int32.Parse(tmp[0]);
                f = Int32.Parse(tmp[1]);
                if (m + f == 0)
                    break;
                Console.WriteLine(m + f);
            }
        }
    }
}
