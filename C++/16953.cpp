#include <iostream>
#include <queue>
#include <set>
using namespace std;

void scanData();
void solveProblem();
void bfs();
void printAnswer();

queue<pair<long long, long long>> bfsQ;
set<long long> visited;
long long a, b;
int answer = -1;

int main()
{
	scanData();
	solveProblem();
	printAnswer();

	return 0;
}

void scanData()
{
	cin >> a >> b;
}

void solveProblem()
{
	visited.insert(a);
	bfsQ.push(pair<long, long> {a, 1});
	bfs();
}

void bfs()
{
	long long cur = bfsQ.front().first;
	long long count = bfsQ.front().second;
	bfsQ.pop();

	if(cur == b)
	{
		answer = count;
		return;
	}



	long long next[2] = {cur * 2, cur * 10 + 1};

	for(int i = 0; i < 2; i++)
	{
		if(visited.find(next[i]) != visited.end())
			continue;
		if(next[i] > b)
			continue;

		visited.insert(next[i]);
		bfsQ.push(pair<int, int> {next[i], count + 1});
	}

	if(bfsQ.empty() == false)
		bfs();
}

void printAnswer()
{
	cout << answer << endl;
}