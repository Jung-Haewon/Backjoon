#include <iostream>
#include <queue>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

priority_queue<long long, vector<long long>, greater<long long>> cards;
long long n, m, tmp;
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
    scanf("%lld %lld", &n, &m);

    for(int i = 0; i < n; i++)
    {
        scanf("%lld", &tmp);
        cards.push(tmp);
    }
}

void solveProblem()
{
    for(int i = 0; i < m; i++)
    {
        long long a = cards.top(); cards.pop();
        long long b = cards.top(); cards.pop();

        cards.push(a+b);
        cards.push(a+b);
    }

    for(int i = 0; i < n; i++)
    {
        ans += cards.top();
        cards.pop();
    }
}

void printAnswer()
{
    cout << ans << endl;
}