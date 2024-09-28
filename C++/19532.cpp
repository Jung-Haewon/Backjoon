#include <iostream>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

int a, b, c, d, e, f;
int x, y;

int main()
{
    scanData();
    solveProblem();
    printAnswer();

    return 0;
}

void scanData()
{
    cin >> a >> b >> c >> d >> e >> f;
}

void solveProblem()
{
    for(int i = -999; i < 1000; i++)
    {
        for(int j = -999; j < 1000; j++)
        {
            if(a*i + b*j == c && d*i + e*j == f)
            {
                x = i;
                y = j;
                return;
            }
        }
    }
}

void printAnswer()
{
    cout << x << " " << y << endl;
}