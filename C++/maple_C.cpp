#include <iostream>
#include <algorithm>
using namespace std;

void scanData();
void solveProblem();
void calBest(int time, int idx, long long money);
void printAnswer();

int n, m, k;
long long damage[49];
long long boss[13][2];
long long ans = 0;

long long dmg, curBest;
long long clearTime[13];

int main()
{
    scanData();
    solveProblem();
    printAnswer();

    return 0;
}

void scanData()
{
    scanf("%d %d %d", &n, &m, &k);

    for(int i = 0; i < n; i++)
        scanf("%lld", &damage[i]);

    for(int i = 0; i < k; i++)
        scanf("%lld %lld", &boss[i][0], &boss[i][1]);

    sort(damage, damage + n);
}

void solveProblem()
{
    for(int i = n - 1; i >= n - m; i--)
    {
        dmg = damage[i];
    
        for(int j = 0; j < k; j++)
        {
            if(boss[j][0] > dmg * 900)
            {
                clearTime[j] = 10000;
                continue;
            }

            if(boss[j][0] % dmg == 0)
                clearTime[j] = boss[j][0] / dmg;
            else
                clearTime[j] = boss[j][0] / dmg + 1;
        }

        curBest = 0;
        calBest(0, 0, 0);
        ans += curBest;
    }
}

void calBest(int time, int idx, long long money)
{
    if(time > 900)
        return;

    if(idx >= k)
    {
        if(money > curBest)
            curBest = money;
        return;
    }

    calBest(time, idx + 1, money);
    calBest(time + clearTime[idx], idx + 1, money + boss[idx][1]);
}

void printAnswer()
{
    cout << ans << endl;
}