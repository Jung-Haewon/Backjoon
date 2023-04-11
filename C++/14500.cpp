#include <iostream>
using namespace std;

void scanData();
void solveProblem();
void dfs(int curX, int curY, int level, int sum, int direct);
void printAnswer();

int paper[502][502];
int n, m;
int answer = 0;

int main()
{
	scanData();
	solveProblem();
	printAnswer();

	return 0;
}

void scanData()
{
	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%d", &paper[i][j]);
}

void solveProblem()
{
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			dfs(i, j, 1, paper[i][j], 0);
}

void dfs(int curX, int curY, int level, int sum, int direct)
{
	if(level >= 4)
	{
		if(answer < sum)
			answer = sum;

		return;
	}

	if(level == 2)
	{
		int twoSum = 0;
		int tmp[4] = { paper[curX][curY + 1], paper[curX][curY - 1],
						paper[curX - 1][curY], paper[curX + 1][curY] };

		for(int i = 0; i < 4; i++)
			if(i == (direct - 1))
				tmp[i] = 0;

		for(int i = 0; i < 3; i++)
			for(int j = i + 1; j < 4; j++)
				if(twoSum < tmp[i] + tmp[j])
					twoSum = tmp[i] + tmp[j];

		if(sum + twoSum > answer)
			answer = sum + twoSum;
	}

	if(paper[curX][curY + 1] != 0 && direct != 1)
		dfs(curX, curY + 1, level + 1, sum + paper[curX][curY + 1], 2);

	if(paper[curX][curY - 1] != 0 && direct != 2)
		dfs(curX, curY - 1, level + 1, sum + paper[curX][curY - 1], 1);

	if(paper[curX + 1][curY] != 0 && direct != 4)
		dfs(curX + 1, curY, level + 1, sum + paper[curX + 1][curY], 3);

	if(paper[curX - 1][curY] != 0 && direct != 3)
		dfs(curX - 1, curY, level + 1, sum + paper[curX - 1][curY], 4);
}

void printAnswer()
{
	cout << answer << endl;
}