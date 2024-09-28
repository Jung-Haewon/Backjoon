#include <iostream>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

long long n, b, c;
long long A[1000001];
long long stack[1000001][3];
long long ans = 0;

int main()
{
    scanData();
    solveProblem();
    printAnswer();

    return 0;
}

void scanData()
{
    scanf("%lld %lld %lld", &n, &b, &c);

    long long *pointer = A;
    for(int i = 0; i < n; i++)
        scanf("%lld", pointer + i);
}

void solveProblem()
{
    if(b <= c)
    {
        for(int i = 0; i < n; i++)
            ans += A[i] * b;

        return;
    }

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
        ans += (stack[i][0] * b) + (stack[i][1] * (b + c)) + (stack[i][2] * (b + c + c));
}

void printAnswer()
{
    cout << ans << endl;
}