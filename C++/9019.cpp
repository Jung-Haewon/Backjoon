#include <iostream>
#include <string>
#include <queue>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

void bfs();

int t;
int a, b;

queue<pair<int, string>> bfsQue;
bool visited[10000];
string answer = "";

int main()
{
	scanData();
	printAnswer();

	return 0;
}

void scanData()
{
	cin >> t;

	for(int i = 0; i < t; i++)
	{
		cin >> a >> b;
		bfsQue = queue<pair<int, string>>();

		for(int i = 0; i < 10000; i++)
			visited[i] = false;

		solveProblem();
	}
}

void solveProblem()
{
	visited[a] = true;
	bfsQue.push(pair<int, string> { a, ""});
	bfs();
}

void bfs()
{
	int cur = bfsQue.front().first;
	string progress = bfsQue.front().second;
	bfsQue.pop();

	if(cur == b)
	{
		answer += progress + "\n";
		return;
	}

	visited[cur] = true;
	int next[4] = 
	{
		(cur * 2) % 10000,
		(cur - 1 < 0)? 9999 : (cur - 1),
		((cur * 10) % 10000) + ((cur * 10) / 10000),
		(cur / 10) + ((cur % 10) * 1000)
	};

	for(int i = 0; i < 4; i++)
	{
		if(visited[next[i]] == true)
			continue;

		visited[next[i]] = true;
		string nextProgress = progress;

		switch(i)
		{
		case 0:
			nextProgress += "D";
			break;
		case 1:
			nextProgress += "S";
			break;
		case 2:
			nextProgress += "L";
			break;
		case 3:
			nextProgress += "R";
			break;
		}

		bfsQue.push(pair<int, string> { next[i], nextProgress});
	}

	bfs();
}

void printAnswer()
{
	cout << answer;
}