#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

void scanData();
void solveProblem();
void bfs();
void printAnswer();

int map[1002][1002];
int lenArr[1002][1002];
bool visited[1002][1002];
queue<vector<int>> nextQue;

int n, m;
int startX, startY;

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
	{
		for(int j = 1; j <= m; j++)
		{
			scanf("%d", &map[i][j]);

			if(map[i][j] == 2)
			{
				startY = i;
				startX = j;
			}
		}
	}
}

void solveProblem()
{
	nextQue.push(vector<int> {startY, startX, 0});
	visited[startY][startX] = true;
	bfs();
}

void bfs()
{
	vector<int> cur = nextQue.front();
	nextQue.pop();

	int y = cur[0];
	int x = cur[1];
	int len = cur[2];

	lenArr[y][x] = len;

	if(map[y - 1][x] == 1 && visited[y - 1][x] != true)
	{
		nextQue.push(vector<int> {y - 1, x, len + 1});
		visited[y - 1][x] = true;
	}

	if(map[y + 1][x] == 1 && visited[y + 1][x] != true)
	{
		nextQue.push(vector<int> {y + 1, x, len + 1});
		visited[y + 1][x] = true;
	}

	if(map[y][x + 1] == 1 && visited[y][x + 1] != true)
	{
		nextQue.push(vector<int> {y, x + 1, len + 1});
		visited[y][x + 1] = true;
	}

	if(map[y][x - 1] == 1 && visited[y][x - 1] != true)
	{
		nextQue.push(vector<int> {y, x - 1, len + 1});
		visited[y][x - 1] = true;
	}

	if(nextQue.empty() != true)
		bfs();
}

void printAnswer()
{
	string answer = "";

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(lenArr[i][j] == 0 && map[i][j] == 1)
				answer += "-1";
			else
				answer += to_string(lenArr[i][j]);

			if(j != m)
				answer += " ";
		}
		answer += "\n";
	}

	cout << answer;
}