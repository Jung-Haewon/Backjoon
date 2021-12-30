using System;

namespace _11655
{
    class Program
    {
        static void Main(string[] args)
        {
            string answer = "";
            string question;
            question = Console.ReadLine();

            for(int i = 0; i < question.Length; i++)
            {
                int tmp = question[i];
                if(tmp >= 'A' && tmp <= 'Z')
                {
                    tmp += 13;
                    if (tmp > 'Z')
                        tmp -= 26;
                }
                else if(tmp >= 'a' && tmp <= 'z')
                {
                    tmp += 13;
                    if (tmp > 'z')
                        tmp -= 26;
                }

                answer += (char)tmp;
            }

            Console.WriteLine(answer);

            //Console.ReadLine();
        }
    }
}
