#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

void scanData();
void solveProblem();
void bfs(int curX, int curY, int level);
void printAnswer();

bool canMove[102][102];
bool visited[102][102];
queue<tuple<int, int, int>> toVisit;
int n, m;
int answer;
bool answerTrigger = false;

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

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			char tmp;
			cin >> tmp;

			if(tmp == '1') 
				canMove[i][j] = true;
		}
	}
}

void solveProblem()
{
	visited[1][1] = true;
	bfs(1, 1, 1);
}

void bfs(int curX, int curY, int level)
{
	//cout << "(" << curX << ", " << curY << ") " << level << endl;

	if(canMove[curX + 1][curY] == true && visited[curX + 1][curY] == false)
	{
		visited[curX + 1][curY] = true;
		toVisit.push(tuple<int, int, int> {curX + 1, curY, level + 1});
	}

	if(canMove[curX - 1][curY] == true && visited[curX - 1][curY] == false)
	{
		visited[curX - 1][curY] = true;
		toVisit.push(tuple<int, int, int> {curX - 1, curY, level + 1});
	}

	if(canMove[curX][curY + 1] == true && visited[curX][curY + 1] == false)
	{
		visited[curX][curY + 1] = true;
		toVisit.push(tuple<int, int, int> {curX, curY + 1, level + 1});
	}

	if(canMove[curX][curY - 1] == true && visited[curX][curY - 1] == false)
	{
		visited[curX][curY - 1] = true;
		toVisit.push(tuple<int, int, int> {curX, curY - 1, level + 1});
	}

	while(true)
	{
		if(toVisit.empty() == true)
			break;

		if(answerTrigger == true)
			break;

		int nextX = get<0>(toVisit.front());
		int nextY = get<1>(toVisit.front());
		int nextLevel = get<2>(toVisit.front());
		toVisit.pop();

		if(nextX == n && nextY == m)
		{
			answer = nextLevel;
			answerTrigger = true;
			break;
		}

		bfs(nextX, nextY, nextLevel);
	}
}

void printAnswer()
{
	cout << answer << endl;
}