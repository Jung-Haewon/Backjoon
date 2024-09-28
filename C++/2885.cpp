#include <iostream>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

int k;
int choco = 1;
int division = 0;

int main()
{
    scanData();
    solveProblem();
    printAnswer();

    return 0;
}

void scanData()
{
    scanf("%d", &k);
}

void solveProblem()
{
    while(choco < k)
        choco *= 2;

    int tmp = choco;
    int cnt = 0;
    while(k != 0)
    {
        if(k >= tmp)
        {
            division = cnt;
            k -= tmp;
        }
        tmp = tmp / 2;
        cnt += 1;
    }
}

void printAnswer()
{
    printf("%d %d\n", choco, division);
}