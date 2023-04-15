#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

void scanData();
void solveProblem();
bool bfsForEat();
void visitClear();
void printAnswer();

int ocean[22][22];
int n;

queue<tuple<int, int, int>> bfsQue;
queue<tuple<int, int>> nextQue;
bool visited[22][22];
int curSharkX, curSharkY, curMinLength;
bool findTrigger;
int sharkSize = 2;
int sharkExp = 0;
int time = 0;

int main()
{
	scanData();
	solveProblem();
	printAnswer();

	return 0;
}

void scanData()
{
	for(int i = 0; i < 22; i++)
		for(int j = 0; j < 22; j++)
			ocean[i][j] = -1;

	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin >> ocean[i][j];

			if(ocean[i][j] == 9)
			{
				ocean[i][j] = 0;
				curSharkX = j;
				curSharkY = i;
			}
		}
	}
}

void solveProblem()
{
	while(true)
	{
		if(sharkExp == sharkSize)
		{
			sharkSize++;
			sharkExp = 0;
		}

		visitClear();
		findTrigger = false;
		bfsQue = queue<tuple<int, int, int>>();
		nextQue = queue<tuple<int, int>>();
		bfsQue.push(tuple<int, int, int> {curSharkX, curSharkY, 0});
		bool isFish = bfsForEat();

		if(isFish == false)
			break;

		int nextX = get<0>(nextQue.front());
		int nextY = get<1>(nextQue.front());
		while(nextQue.empty() != true)
		{
			if(nextY > get<1>(nextQue.front()))
			{
				nextY = get<1>(nextQue.front());
				nextX = get<0>(nextQue.front());
			}
			else if(nextY == get<1>(nextQue.front()))
			{
				if(nextX > get<0>(nextQue.front()))
				{
					nextY = get<1>(nextQue.front());
					nextX = get<0>(nextQue.front());
				}
			}

			nextQue.pop();
		}

		ocean[nextY][nextX] = 0;
		curSharkX = nextX;
		curSharkY = nextY;
		time += curMinLength;
		sharkExp++;
	}
}

bool bfsForEat()
{
	int x = get<0>(bfsQue.front());
	int y = get<1>(bfsQue.front());
	int level = get<2>(bfsQue.front());
	bfsQue.pop();

	//cout << y << " " << x << endl;

	if(findTrigger == true)
		if(level > curMinLength)
			return true;

	if(ocean[y][x] != 0 && ocean[y][x] != sharkSize)
	{
		//cout << y << " " << x << endl;

		curMinLength = level;
		findTrigger = true;
		nextQue.push(tuple<int, int> {x, y});

		if(bfsQue.empty() == false)
			bfsForEat();
		return true;
	}

	if(visited[y - 1][x] == false && ocean[y - 1][x] != -1 && ocean[y - 1][x] <= sharkSize)
	{
		visited[y - 1][x] = true;
		bfsQue.push(tuple<int, int, int> {x, y - 1, level + 1});
	}
	if(visited[y][x - 1] == false && ocean[y][x - 1] != -1 && ocean[y][x - 1] <= sharkSize)
	{
		visited[y][x - 1] = true;
		bfsQue.push(tuple<int, int, int> {x - 1, y, level + 1});
	}
	if(visited[y][x + 1] == false && ocean[y][x + 1] != -1 && ocean[y][x + 1] <= sharkSize)
	{
		visited[y][x + 1] = true;
		bfsQue.push(tuple<int, int, int> {x + 1, y, level + 1});
	}
	if(visited[y + 1][x] == false && ocean[y + 1][x] != -1 && ocean[y + 1][x] <= sharkSize)
	{
		visited[y + 1][x] = true;
		bfsQue.push(tuple<int, int, int> {x, y + 1, level + 1});
	}

	if(bfsQue.empty() == true)
		return false;
	else
		return bfsForEat();
}

void visitClear()
{
	for(int i = 0; i < 22; i++)
		for(int j = 0; j < 22; j++)
			visited[i][j] = false;
}

void printAnswer()
{
	cout << time << endl;
}