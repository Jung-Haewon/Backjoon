#include <iostream>
#include <queue>
using namespace std;

void input();
void bfs();
bool valid(int x, int y);
void output();

int m, n;
int arr[1000][1000];
int curTomato, nextTomato;
int totalTomato = 0;
int sumTomato = 0;
int ans = -1;
queue<pair<int, int>> curArr;

int main(void)
{
	input();
	bfs();
	output();
}

void input()
{
	scanf("%d %d", &m, &n);

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);

			if(arr[i][j] == 1)
			{
				curTomato++;
				curArr.push({i, j});
			}

			if(arr[i][j] != - 1)
				totalTomato++;
		}
	}
}

void bfs()
{
	while(curArr.empty() == false)
	{
		for(int i = 0; i < curTomato; i++)
		{
			sumTomato++;
			int curX = curArr.front().first;
			int curY = curArr.front().second;
			curArr.pop();

			int nextXY[4][2] = {{curX + 1, curY}, {curX - 1, curY}, {curX, curY + 1}, {curX, curY - 1}};
			
			for(int j = 0; j < 4; j++)
			{
				int nextX = nextXY[j][0];
				int nextY = nextXY[j][1];

				if(valid(nextX, nextY) == false)
					continue;

				arr[nextX][nextY] = 1;
				nextTomato++;
				curArr.push({nextX, nextY});
			}
		}

		curTomato = nextTomato;
		nextTomato = 0;
		ans++;
	}
}

bool valid(int x, int y)
{
	if(x < 0 || y < 0)
		return false;
	if(x >= n || y >= m)
		return false;
	if(arr[x][y] != 0)
		return false;
	return true;
}

void output()
{
	if(sumTomato != totalTomato)
		printf("-1\n");
	else
		printf("%d\n", ans);
}