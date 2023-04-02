#include <iostream>
using namespace std;

void scanData();
void solveProblem();
void dfs(int start, int cur);
void printAnswer();

bool nodes[100][100];
bool answer[100][100];
int n;

int main()
{
	scanData();
	solveProblem();
	printAnswer();

	return 0;
}

void scanData()
{
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &nodes[i][j]);
}

void solveProblem()
{
	for(int i = 0; i < n; i++)
		dfs(i, i);
}

void dfs(int start, int cur)
{
	for(int i = 0; i < n; i++)
	{
		if(nodes[cur][i] == false)
			continue;
		if(answer[start][i] == true)
			continue;

		answer[start][i] = true;
		dfs(start, i);
	}
}

void printAnswer()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n-1; j++)
			cout << answer[i][j] << " ";

		cout << answer[i][n-1] << endl;
	}
}