#include <iostream>
#include <queue>
using namespace std;

void scanData();
void solveProblem();
void bfs();
void printAnswer();

queue<pair<int, int>> bfsQue;
int board[101];
bool wasSearched[101];
int n, m;
int answer;

int main()
{
	scanData();
	solveProblem();
	printAnswer();

	return 0;
}

void scanData()
{
	int x, y;

	scanf("%d %d", &n, &m);

	for(int i = 0; i < n + m; i++)
	{
		scanf("%d %d", &x, &y);
		board[x] = y;
	}
}

void solveProblem()
{
	bfsQue.push(pair<int, int> {1, 0});
	bfs();
}

void bfs()
{
	int cur = bfsQue.front().first;
	int level = bfsQue.front().second;
	bfsQue.pop();

	//cout << cur << " " << level << endl;

	if(cur == 100)
	{
		answer = level;
		return;
	}

	wasSearched[cur] = true;

	for(int i = 1; i <= 6; i++)
	{
		if(cur + i > 100)
			break;

		if(wasSearched[cur + i] == true)
			continue;

		if(board[cur + i] == 0)
			bfsQue.push(pair<int, int> {cur + i, level + 1});
		else
			bfsQue.push(pair<int, int> {board[cur + i], level + 1});
	}

	bfs();
}

void printAnswer()
{
	cout << answer << endl;
}