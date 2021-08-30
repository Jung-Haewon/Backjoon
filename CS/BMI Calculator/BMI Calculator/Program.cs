using System;

namespace BMI_Calculator
{
    class Program
    {
        static void Main(string[] args)
        {
            double height, weight, BMI;
            int cnt;
            string[] state = { "저체중", "정상체중", "경도비만", "비만", "고도비만" };


            Console.WriteLine("키를 입력하세요(cm): ");
            height = Double.Parse(Console.ReadLine())/100;
            Console.WriteLine("몸무게를 입력하세요(kg): ");
            weight = Double.Parse(Console.ReadLine());

            BMI = weight / (height * height);

            if (BMI < 20) cnt = 0;
            else if (BMI < 25) cnt = 1;
            else if (BMI < 30) cnt = 2;
            else if (BMI < 40) cnt = 3;
            else cnt = 4;

            Console.WriteLine("당신의 BMI 지수는 {0:.00}이고, 이것은 {1}을 의미합니다.", BMI, state[cnt]);
        }
    }
}
