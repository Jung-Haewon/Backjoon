#include <iostream>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

int arr[1001][1001];
int n, k;
int ans;

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
}

void solveProblem()
{
    arr[1][0] = 1;
    arr[1][1] = 1;

    for(int i = 2; i < 1001; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(j == 0)
                arr[i][j] = 1;
            else
                arr[i][j] = (arr[i-1][j-1] + arr[i-1][j]) % 10007;
        }
    }
}

void printAnswer()
{
    printf("%d\n", arr[n][k]);
}