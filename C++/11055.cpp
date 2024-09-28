#include <iostream>
#include <vector>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

int n;
int arr[1000];
int best[1000];
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
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        best[i] = arr[i];
    }
}

void solveProblem()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[j] >= arr[i])
                continue;

            if(best[j] + arr[i] > best[i])
                best[i] = best[j] + arr[i];
        } 
    }

    for(int i = 0; i < n; i++)
        if(best[i] > ans)
            ans = best[i];
}

void printAnswer()
{
    cout << ans << endl;
}