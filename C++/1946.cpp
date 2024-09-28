#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solveProblem();
void solveTestCase();

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
        solveTestCase();
}

void solveTestCase()
{
    scanf("%d", &n);
    vector<pair<int, int>> arr;
    int lowerBest = n;
    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        int s, m;
        scanf("%d %d", &s, &m);

        arr.push_back(pair<int, int> {s, m});
    }

    sort(arr.begin(), arr.end());

    for(auto a : arr)
    {
        if(a.second <= lowerBest)
        {
            ans += 1;
            lowerBest = a.second;
        }
    }

    printf("%d\n", ans);
}