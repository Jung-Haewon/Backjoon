#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void scanData();
void solveProblem();

int n, k, tmp;
int arr[10000];
priority_queue<int> dis;

int main()
{
    scanData();
    solveProblem();

    return 0;
}

void scanData()
{
    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    sort(arr, arr + n);

    for(int i = 0; i < n - 1; i++)
        dis.push(arr[i+1] - arr[i]);
}

void solveProblem()
{
    int cnt = k - 1;

    while(true)
    {
        if(dis.empty() == true)
            break;
        if(cnt == 0)
            break;

        dis.pop();
        cnt--;
    }

    int ans = 0;
    while(dis.empty() == false)
    {
        ans += dis.top();
        dis.pop();
    }

    cout << ans << endl;
}