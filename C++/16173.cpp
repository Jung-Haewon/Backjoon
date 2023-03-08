#include <iostream>
#include <queue>
using namespace std;

void scanData();
void bfs();
void printAnswer();

int n;
int gameMap[3][3];
queue <pair<int, int>> bfsQ;
bool answer = false;

int main()
{
	scanData();
	bfs();
	printAnswer();

	return 0;
}

void scanData()
{
	cin >> n;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> gameMap[i][j];
}

void bfs()
{
	int curX, curY, distance;
	bfsQ.push({0, 0});

	while(true)
	{
		if(bfsQ.empty() == true)
			break;

		curX = bfsQ.front().first;
		curY = bfsQ.front().second;
		distance = gameMap[curX][curY];
		bfsQ.pop();

		//cout << curX << " " << curY << " " << distance << endl;

		if(distance == -1)
		{
			answer = true;
			break;
		}
		if(distance == 0)
			continue;

		if(curX + distance < n)
			bfsQ.push({curX + distance, curY});
		if(curY + distance < n)
			bfsQ.push({curX, curY + distance});
	}
}

void printAnswer()
{
	if(answer == true)
		cout << "HaruHaru" << endl;
	else
		cout << "Hing" << endl;
}