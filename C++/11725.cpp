#include <iostream>
#include <vector>
#include <string>
using namespace std;

void scanData();
void solveProblem();
void dfs(int cur);
void printAnswer();

vector<vector<int>> graph;
int parent[100001];
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
	graph.assign(100001, vector<int> {});

	scanf("%d", &n);

	int x, y;
	for(int i = 0; i < n - 1; i++)
	{
		scanf("%d %d", &x, &y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
}

void solveProblem()
{
	dfs(1);
}

void dfs(int cur)
{
	for(auto iter = graph[cur].begin(); iter != graph[cur].end(); iter++)
	{
		if(parent[*iter] != 0)
			continue;

		parent[*iter] = cur;
		dfs(*iter);
	}
}

void printAnswer()
{
	string answer = "";

	for(int i = 2; i <= n; i++)
		answer += to_string(parent[i]) + "\n";

	cout << answer;
}