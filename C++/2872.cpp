#include <iostream>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

int n, ans;
int book[300000];

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
        scanf("%d", &book[i]);

    ans = n;
}

void solveProblem()
{
    int target = n;

    for(int i = n - 1; i >= 0; i--)
    {
        if(book[i] == target)
        {
            ans--;
            target--;
        }
    }
}

void printAnswer()
{
    cout << ans << endl;
}