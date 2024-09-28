#include <iostream>
#include <cstdlib>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

long long n, k;
long long a[500000];
long long best;

int main()
{
    scanData();
    solveProblem();
    printAnswer();

    return 0;
}

void scanData()
{
    scanf("%lld %lld", &n, &k);

    for(int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
}

void solveProblem()
{
    best = a[0] - a[1] - k;

    for(int i = 0; i < 100000; i++)
    {
        int x = (rand() * rand()) % n;
        int y = (rand() * rand()) % n;

        if(x == y)
            continue;

        int tmp = abs(a[x] - a[y]) - (k * (abs(x - y)));
        if(tmp > best)
            best = tmp;
    }
}

void printAnswer()
{
    cout << best << endl;
}