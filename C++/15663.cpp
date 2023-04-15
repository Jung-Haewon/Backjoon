#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

void scanData();
void solveProblem();
void regression(string str, int len, set<int> visited);
void printAnswer();

set<string> progression;

int n, m;
int arr[8];
string answer;

int main()
{
	scanData();
	solveProblem();
	printAnswer();

	return 0;
}

void scanData()
{
	cin >> n >> m;

	for(int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);
}

void solveProblem()
{
	set<int> visited;
	regression("", 0, visited);
}

void regression(string str, int len, set<int> visited)
{
	if(len == m)
	{
		if(progression.find(str) == progression.end())
		{
			answer += str + "\n";
			progression.insert(str);
		}
		
		return;
	}

	if(len != 0)
		str = str + " ";

	for(int i = 0; i < n; i++){
		if(visited.find(i) != visited.end())
			continue;

		set<int> nextVisited = visited;
		nextVisited.insert(i);
		regression(str + to_string(arr[i]), len + 1, nextVisited);
	}
}

void printAnswer()
{
	cout << answer;
}