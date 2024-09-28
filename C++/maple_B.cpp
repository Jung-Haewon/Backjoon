#include <iostream>
#include <algorithm>
using namespace std;

void scanData();
void solveProblem();

int n, m;
int a[1000000];
int b[1000000];

int main()
{
    scanData();
    solveProblem();

    return 0;
}

void scanData()
{
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(int i = 0; i < m; i++)
        scanf("%d", &b[i]);

    sort(a, a + n);
    sort(b, b + m);
}

void solveProblem()
{
    int aCnt = 0, aTimer = 0;
    int bCnt = 0, bTimer = 0;

    for(int i = 0; i < n; i++)
    {
        if(aTimer <= a[i])
        {
            aCnt++;
            aTimer = a[i] + 100;
        }
    }

    for(int i = 0; i < m; i++)
    {
        if(bTimer <= b[i])
        {
            bCnt++;
            bTimer = b[i] + 360;
        }
    }

    printf("%d %d\n", aCnt, bCnt);
}