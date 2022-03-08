#include <iostream>
#include <vector>
using namespace std;

void dfs(int num);

int n, m;
int ans = 0;
bool checkArr[1001];
vector<int> arr[1001];

int main(void)
{
	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	for(int i = 1; i <= n; i++)
	{
		if(checkArr[i] == true)
			continue;

		dfs(i);
		ans++;
	}

	printf("%d\n", ans);

	return 0;
}

void dfs(int num)
{
	checkArr[num] = true;

	for(int node : arr[num])
		if(checkArr[node] != true)
			dfs(node);
}