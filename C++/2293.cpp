#include <iostream>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

int n, k;
int coins[100];

int main()
{
    scanData();
    solveProblem();
    printAnswer();

    return 0;
}

void scanData()
{
    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++)
        scanf("%d", &coins[i]);
}

void solveProblem()
{

}

void printAnswer()
{
    
}