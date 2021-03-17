/*문제풀이 해설
* n-2개가 주어졌을때:
* 구하고자하는 답이 각각 x, y 라고 할때
* x + y의 값과 x^2 + y^2의 값을 구해서 x와 y의 값을 구합니다
* 2개의 미지수와 2개의 방정식이 만들어지므로 x, y의 값을 수학적으로 도출해낼수 있음
*
* n-1개가 주어졌을때:
* 1부터 n까지 더한 값에서 주어진값을 더한 값을 빼면 미지수 x를 구할수 있습니다
*
* 요약:
* int 타입 데이터: 최대 5개
* long int 타입 데이터: 최대 6개
* 최대 5*4 + 6*8 = 68 byte의 메모리를 차지합니다.
*/


#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;
//조교님께서 확인하시기 쉬우도록 나름대로 주석을 많이 작성해 놓았습니다!
//늘 고생하십니다!

int main(){
    //입력파트
    ifstream in("deck.inp");
    ofstream out("deck.out");

    int N;
    in >> N;
    


    //문제풀이 파트
    long int ans1 = N * (N + 1) / 2; //1부터 N까지의 합
    long int ans2 = 0; //1^2부터 N^2까지의 합
    for(int i = 1; i <= N; i++)
    {
        ans2 += i*i;
    }

    int cnt = -1; //n-1개인지, n-2개인지 판단하기 위한 변수, 입력과정에서 마지막 개행까지 읽어들이는 바람에 -1부터 시작합니다.
    long int sum1 = 0; //실제 카드들에 적힌 숫자들의 합
    long int sum2 = 0; //실제 카드들에 적힌 숫자들의 제곱의 합

    while(in)
    {
        long int tmp = 0;
        in >> tmp;
        sum1 += tmp;
        sum2 += tmp*tmp;
        cnt++;
    }
    ans1 -= sum1; //x + y의 값을 구합니다. n-1개 주어졌을때는 이 값이 x의 값이 됩니다.
    ans2 -= sum2; //x^2 + y^2의 값을 구합니다.



    //출력 파트
    if(N-cnt == 1)
        out << ans1 << "\n"; //n-1개 주어졌을때의 출력
    else //n-2개 주어졌을때의 출력
    {
        /* ans1과 ans2를 이용한 정답 찾아내기
        ans1**2 - ans2의 값은 2*x*y입니다
        * 저희는 이것을 이용하여 (x-y)**2의 값을 먼저 구한다음 x-y의 값을 구합니다
        * 그러고난뒤 x + y와 x - y의 연립방정식을 통해서 x, y의 값을 구합니다
        */
        long int ans3 = sqrt((ans2 - (ans1*ans1 - ans2))); //x-y의 값
        int x = abs((ans3 + ans1)/2);
        int y = abs((ans3 - ans1)/2);
        if(x <= y)
            out << x << "\n" << y << "\n";
        else
            out << y << "\n" << x << "\n";
    }

    in.close();
    out.close(); 
    return 0;
}