#include <iostream>
#include <set>
#include <queue>
#include <string>
using namespace std;

void scanData();
void dfs(int cur);
void bfs(int cur);

int nodes[1001][1001];
set<int> dfsVisited;
set<int> bfsVisited;
queue<int> bfsQue;
int n, m, v;
string answer = "";

int main()
{
	scanData();
	dfs(v);
	answer += "\n" + to_string(v);
	bfs(v);
	cout << answer << endl;

	return 0;
}

void scanData()
{
	cin >> n >> m >> v;

	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		nodes[a][b] = 1;
		nodes[b][a] = 1;
	}

	answer += to_string(v);
	dfsVisited.insert(v);
	bfsVisited.insert(v);
	bfsQue.push(v);
}

void dfs(int cur)
{
	for(int i = 1; i < 1001; i++)
	{
		if(nodes[cur][i] == 0)
			continue;
		if(dfsVisited.find(i) != dfsVisited.end())
			continue;

		answer += " " + to_string(i);
		dfsVisited.insert(i);
		dfs(i);
	}
}

void bfs(int cur)
{
	bfsQue.pop();

	for(int i = 1; i < 1001; i++)
	{
		if(nodes[cur][i] == 0)
			continue;
		if(bfsVisited.find(i) != bfsVisited.end())
			continue;

		answer += " " + to_string(i);
		bfsVisited.insert(i);
		bfsQue.push(i);
	}

	while(bfsQue.empty() == false)
	{
		bfs(bfsQue.front());
	}
}