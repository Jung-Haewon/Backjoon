#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

void scanData();
void solveProblem();
void regression(string str, int cur, int len);
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
	regression("", 0, 0);
}

void regression(string str, int cur, int len)
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

	for(int i = cur; i < n; i++)
		regression(str + to_string(arr[i]), i, len + 1);
}

void printAnswer()
{
	cout << answer;
}