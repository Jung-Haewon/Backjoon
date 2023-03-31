#include <iostream>
#include <set>
#include <queue>
using namespace std;

void scanData();
void solveProblem();
void bfs(int cur, int level);
void printAnswer();

bool node[101][101];
int n, m;

set<int> visited;
queue<pair<int, int>> toVisit;
int baconNum;
int answer = 1;

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
	int tmp1, tmp2;

	for(int i = 0; i < m; i++)
	{
		scanf("%d %d", &tmp1, &tmp2);
		node[tmp1][tmp2] = true;
		node[tmp2][tmp1] = true;
	}
}

void solveProblem()
{
	int minBaconNum;

	for(int i = 1; i <= n; i++)
	{
		visited.clear();
		visited.insert(i);
		toVisit = queue<pair<int, int>>();
		baconNum = 0;
		bfs(i, 0);

		//cout << "name: " << i << endl;
		//cout << "baconNum: " << baconNum << endl;

		if(i == 1)
			minBaconNum = baconNum;

		if(baconNum < minBaconNum)
		{
			answer = i;
			minBaconNum = baconNum;
		}
	}
}

void bfs(int cur, int level)
{
	//cout << cur << " " << level << endl;
	baconNum += level;

	for(int i = 1; i <= n; i++)
	{
		if(node[cur][i] == false || visited.find(i) != visited.end())
			continue;

		toVisit.push(pair<int, int> {i, level + 1});
		visited.insert(i);
	}

	while(true)
	{
		if(toVisit.empty() == true)
			break;

		int next = toVisit.front().first;
		int nextLevel = toVisit.front().second;
		toVisit.pop();
		bfs(next, nextLevel);
	}
}

void printAnswer()
{
	cout << answer << endl;
}