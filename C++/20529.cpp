#include <iostream>
#include <string>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

int t, n, ans;
string mbti[100000];

int main()
{
    scanData();

    return 0;
}

void scanData()
{
    cin >> t;

    for(int i = 0; i < t; i++)
    {
        cin >> n;
        ans = 12;

        for(int j = 0; j < n; j++)
            cin >> mbti[j];

        solveProblem();
        printAnswer();
    }
}

void solveProblem()
{
    if(n > 48)
    {
        ans = 0;
        return;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            for(int k = j + 1; k < n; k++)
            {
                int tmp = 0;

                for(int a = 0; a < 4; a++)
                    if(mbti[i][a] != mbti[j][a])
                        tmp++;

                for(int a = 0; a < 4; a++)
                    if(mbti[j][a] != mbti[k][a])
                        tmp++;

                for(int a = 0; a < 4; a++)
                    if(mbti[k][a] != mbti[i][a])
                        tmp++;

                if(tmp < ans)
                    ans = tmp;
            }
        }
    }
}

void printAnswer()
{
    cout << ans << endl;
}