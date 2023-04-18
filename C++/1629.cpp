#include <iostream>
#include <vector>
#include <set>
using namespace std;

void scanData();
void solveProblem();
void dP();
void printAnswer();

vector<long long> modResult;
set<long long> visited;
long long a, b, c;

int main()
{
	scanData();
	solveProblem();
	printAnswer();

	return 0;
}

void scanData()
{
	cin >> a >> b >> c;
}

void solveProblem()
{
	dP();
}

void dP()
{
	long long cur = a % c;

	while(true)
	{
		modResult.push_back(cur);
		visited.insert(cur);

		cur = (cur * a) % c;

		if(visited.find(cur) != visited.end())
			break;
	}
}

void printAnswer()
{
	cout << modResult[(b % modResult.size()) - 1] << endl;
}