#include <iostream>
#include <vector>
#include <set>
using namespace std;

void initData();
void scanData();
void solveProblem();
void dijkstra(int cur);
void printAnswer();

int bus[1001][1001];
int leastLen[1001];
bool visited[1001];
int n, m;
int start, ended;

set<pair<int, int>> canVisit;

int main()
{
	initData();
	scanData();

	solveProblem();
	printAnswer();

	return 0;
}

void initData()
{
	for(int i = 0; i < 1001; i++)
		for(int j = 0; j < 1001; j++)
			bus[i][j] = -1;

	for(int i = 0; i < 1001; i++)
		leastLen[i] = -1;
}

void scanData()
{
	scanf("%d", &n);
	scanf("%d", &m);

	for(int i = 0; i < m; i++)
	{
		int from, to, pay;
		scanf("%d %d %d", &from, &to, &pay);

		bus[from][to] = pay;
	}

	scanf("%d %d", &start, &ended);
}

void solveProblem()
{
	dijkstra(start);
}

void dijkstra(int cur)
{
	for(int i = 1; i < 1001; i++)
	{
		if(bus[cur][i] == -1)
			continue;
		if(visited[i] == true)
			continue;

		newLen = bus[cur][i];
	}
}

void printAnswer()
{

}