#include <iostream>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

int n;
int A[10001];
int stack[10001][3];
int ans = 0;

int main()
{
    scanData();
    solveProblem();
    printAnswer();

    return 0;
}

void scanData()
{
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &A[i]);
}

void solveProblem()
{
    stack[0][0] = A[0];

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < A[i]; j++)
        {
            if(stack[i-1][0] > 0)
            {
                stack[i-1][0] -= 1;
                stack[i-1][1] += 1;
            }
            else if(i > 1 && stack[i-2][1] > 0)
            {
                stack[i-2][1] -= 1;
                stack[i-2][2] += 1;
            }
            else
                stack[i][0] += 1;
        }
    }

    for(int i = 0; i < n; i++)
        ans += (stack[i][0] * 3) + (stack[i][1] * 5) + (stack[i][2] * 7);
}

void printAnswer()
{
    cout << ans << endl;
}