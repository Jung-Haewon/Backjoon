using System;

namespace _2985
{
    class Program
    {
        static void Main(string[] args)
        {
            //문제 조건
            string[] tmp = Console.ReadLine().Split();
            int x = Int32.Parse(tmp[0]);
            int y = Int32.Parse(tmp[1]);
            int z = Int32.Parse(tmp[2]);

            char[] ans = new char[2];

            //문제 풀이
            if (x + y == z) { ans[0] = '+'; ans[1] = '='; }
            else if (x - y == z) { ans[0] = '-'; ans[1] = '='; }
            else if (x * y == z) { ans[0] = '*'; ans[1] = '='; }
            else if (x / y == z) { ans[0] = '/'; ans[1] = '='; }
            else if (x == y + z) { ans[0] = '='; ans[1] = '+'; }
            else if (x == y - z) { ans[0] = '='; ans[1] = '-'; }
            else if (x == y * z) { ans[0] = '='; ans[1] = '*'; }
            else { ans[0] = '='; ans[1] = '/'; }

            Console.WriteLine($"{x}{ans[0]}{y}{ans[1]}{z}");
        }
    }
}
