#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solveProblem();
void solveTestCase();

int arr[10000];
int t, n;

int main()
{
    solveProblem();

    return 0;
}

void solveProblem()
{
    scanf("%d", &t);

    for(int i = 0; i < t; i++)
    {
        scanf("%d", &n);

        for(int j = 0; j < n; j++)
            scanf("%d", &arr[j]);

        solveTestCase();
    }
}

void solveTestCase()
{
    sort(arr, arr + n);

    vector<int> ansArr;

    for(int i = 0; i < n; i += 2)
        ansArr.push_back(arr[i]);

    if(n % 2 == 1)
        for(int i = n - 2; i >= 0; i -= 2)
            ansArr.push_back(arr[i]);
    else
        for(int i = n - 1; i >= 0; i -= 2)
            ansArr.push_back(arr[i]);

    int ans = ansArr[n-1] - ansArr[0];

    for(int i = 0; i < n - 1; i++)
    {
        int tmp = abs(ansArr[i] - ansArr[i + 1]);

        if(tmp > ans)
            ans = tmp;
    }

    printf("%d\n", ans);
}