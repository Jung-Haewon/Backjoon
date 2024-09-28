#include <iostream>
#include <queue>
using namespace std;

void scanData();
void solveProblem();
void bfs();
void printAnswer();

struct BfsNode
{
	int x;
	int y;
	int distance;
	bool useBomb;
};

struct VisitNode
{
	bool visited = false;
	int noBombMin;
	int useBombMin;
};

VisitNode visited[1002][1002];
char graph[1002][1002];
queue<BfsNode> bfsQue;
int n, m;
int ans = -1;

int main()
{
    scanData();
    solveProblem();
    printAnswer();

    return 0;
}

void scanData()
{
	char tmp;
	cin >> n >> m;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> graph[i][j];
}

void solveProblem()
{
	visited[1][1].visited = true;
	visited[1][1].noBombMin = 1;
	visited[1][1].useBombMin = 1;	
	BfsNode bfsNode = {1, 1, 1, false};

	bfsQue.push(bfsNode);
	bfs();
}

void bfs()
{
	BfsNode curNode = bfsQue.front();
	bfsQue.pop();

	int x = curNode.x;
	int y = curNode.y;
	int dis = curNode.distance;
	bool useBomb = curNode.useBomb;

	if(x == n && y == m)
	{
		if(bfsQue.empty() != true)
			bfs();
		return;
	}

	//cout << x << " " << y << " " << dis << " " << useBomb << endl;

	for(int i = 0; i < 4; i++)
	{
		int nextX = x;
		int nextY = y;
		int nextDis = dis + 1;

		switch(i)
		{
		case 0:
			nextX += 1;
			break;
		case 1:
			nextX -= 1;
			break;
		case 2:
			nextY += 1;
			break;
		case 3:
			nextY -= 1;
			break;
		}

		//폭탄 없이 지나갈 수 있고, 폭탄도 가지고 있을 경우
		if(graph[nextX][nextY] == '0' && useBomb == false)
		{
			if(visited[nextX][nextY].visited == false || visited[nextX][nextY].useBombMin > nextDis)
			{
				visited[nextX][nextY].visited = true;
				visited[nextX][nextY].noBombMin = nextDis;
				visited[nextX][nextY].useBombMin = nextDis;	

				BfsNode nextNode = {nextX, nextY, nextDis, useBomb};
				bfsQue.push(nextNode);
			}
			else if(visited[nextX][nextY].noBombMin > nextDis || visited[nextX][nextY].noBombMin == 0)
			{
				visited[nextX][nextY].noBombMin = nextDis;

				BfsNode nextNode = {nextX, nextY, nextDis, useBomb};
				bfsQue.push(nextNode);
			}
		}
		//폭탄 없이 지나갈 수 있고, 폭탄은 이미 사용한 경우
		else if(graph[nextX][nextY] == '0')
		{
			if(visited[nextX][nextY].visited == false || visited[nextX][nextY].useBombMin > nextDis)
			{
				visited[nextX][nextY].visited = true;
				visited[nextX][nextY].useBombMin = nextDis;	

				BfsNode nextNode = {nextX, nextY, nextDis, useBomb};
				bfsQue.push(nextNode);
			}
		}
		//길이 막혀 있지만, 폭탄이 있는 경우
		else if(graph[nextX][nextY] == '1' && useBomb == false)
		{
			if(visited[nextX][nextY].visited == false || visited[nextX][nextY].useBombMin > nextDis)
			{
				visited[nextX][nextY].visited = true;
				visited[nextX][nextY].useBombMin = nextDis;	

				BfsNode nextNode = {nextX, nextY, nextDis, true};
				bfsQue.push(nextNode);
			}
		}
	}

	if(bfsQue.empty() != true)
		bfs();
}

void printAnswer()
{
	if(visited[n][m].visited == true)
		ans = visited[n][m].useBombMin;

    cout << ans << endl;
}