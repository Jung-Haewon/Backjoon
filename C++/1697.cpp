#include <iostream>
#include <queue>
#define MAXVALUE 200001
using namespace std;

void input();
void bfs();
void output();

int n, k, ans;
bool checkArr[MAXVALUE];
queue<pair<int, int>> curArr;

int main(void)
{
	input();
	bfs();
	output();
}

void input()
{
	scanf("%d %d", &n, &k);
}

void bfs()
{
	curArr.push({n, 0});
	checkArr[n] = true;

	while(true)
	{
		int cur = curArr.front().first;
		int curDepth = curArr.front().second;
		curArr.pop();

		if(cur == k)
		{
			ans = curDepth;
			break;
		}

		int nextArr[3] = {cur * 2, cur + 1, cur - 1};

		for(int next : nextArr)
		{
			if(next > MAXVALUE || next < 0)
				continue;

			if(checkArr[next] == true)
				continue;

			checkArr[next] = true;
			curArr.push({next, curDepth + 1});
		}
	}
}

void output()
{
	printf("%d\n", ans);
}