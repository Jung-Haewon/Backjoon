#include <iostream>
#include <vector>
using namespace std;

void dfs(int a);

vector<int> vec[101];
bool chk[101];
int com, n;
int ans = -1;

int main(void)
{
	scanf("%d", &com);
	scanf("%d", &n);

	while(n--)
	{
		int x, y;
		scanf("%d %d", &x, &y);

		vec[x].push_back(y);
		vec[y].push_back(x);
	}

	dfs(1);

	printf("%d\n", ans);

	return 0;
}

void dfs(int a)
{
	if(chk[a] == true)
		return;

	chk[a] = true;
	ans++;

	for(auto v : vec[a])
		dfs(v);
}