#include <iostream>
#include <algorithm>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

int n, k;
int cat[5000];
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
    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++)
        scanf("%d", &cat[i]);

    sort(cat, cat + n);
}

void solveProblem()
{
    int front = 0;
    int end = n - 1;

    while(front < end)
    {
        if(cat[front] + cat[end] <= k)
        {
            ans++;
            front++;
        }
        end--;
    }
}

void printAnswer()
{
    cout << ans << endl;
}