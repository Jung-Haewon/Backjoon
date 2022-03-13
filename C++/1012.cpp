#include <iostream>
#include <vector>
using namespace std;

void input();
void dfs(int x, int y);

bool cabbage[50][50];
bool selected[50][50];
int t, m, n, k;
int ans;

int main(void)
{
	scanf("%d", &t);

	while(t--)
	{
		ans = 0;
		input();

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if(cabbage[i][j] == false)
					continue;
				if(selected[i][j] == true)
					continue;

				dfs(i, j);
				ans++;
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}

void input()
{
	scanf("%d %d %d", &m, &n, &k);

	for(int i = 0; i < 50; i++){
		for(int j = 0; j < 50; j++)
		{
			cabbage[i][j] = false;
			selected[i][j] = false;
		}
	}

	for(int i = 0; i < k; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		cabbage[y][x] = true;
	}
}

void dfs(int x, int y)
{
	selected[x][y] = true;

	int near[4][2] = 
	{
		{x, y+1}, 
		{x, y-1}, 
		{x+1, y}, 
		{x-1, y}
	};

	for(int i = 0; i < 4; i++)
	{
		int newX = near[i][0];
		int newY = near[i][1];

		if(newX >= 0 && newX < n && newY >= 0 && newY < m)
		{
			if(cabbage[newX][newY] == false)
				continue;
			if(selected[newX][newY] == true)
				continue;
			dfs(newX, newY);
		}
	}
}