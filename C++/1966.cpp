#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

int main(void)
{
	int arr[100] = {0, };
	int prio[100] = {0, };

	int t, n, m;
	scanf("%d", &t);

	while(t--)
	{
		scanf("%d %d", &n, &m);
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
			prio[i] = arr[i];
		}

		sort(prio, prio + n, compare);
		queue<int> priQ;
		for(int i = 0; i < n; i++)
			priQ.push(prio[i]);

		int ans = 0;
		int cnt = 0;

		while(true)
		{
			if(arr[cnt] == priQ.front())
			{
				ans++;
				priQ.pop();
				arr[cnt] = 0;

				if(cnt == m)
					break;
			}
			cnt++;
			if(cnt >= n)
				cnt = 0;
		}

		printf("%d\n", ans);
	}
}