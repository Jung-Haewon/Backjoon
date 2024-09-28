#include <iostream>
using namespace std;

void setData();
void solveProblem();
void printAnswer();

char hands[100];
int cnt;

int main()
{
    setData();
    solveProblem();
    printAnswer();

    return 0;
}

void setData()
{
    for(int i = 0 ; i < 100; i++)
        hands[i] = '2';

    cin >> cnt;
}

void solveProblem()
{
    for(int i = 0; i < 100; i++)
    {
        if(cnt == 100)
            return;

        hands[i] = '0';
        cout << "? " << hands << endl;

        int result;
        cin >> result;

        if(result < cnt) //가위였을때
        {
            hands[i] = '2';
        }
        else if(result == cnt) //보였을때
        {
            hands[i] = '5';
            cnt++;
        }
        else if(result > cnt) //묵이였을때
        {
            hands[i] = '0';
            cnt++;
        }
    }
}

void printAnswer()
{
    cout << "! " << hands << endl;
}