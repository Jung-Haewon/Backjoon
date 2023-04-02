#include <iostream>
#include <string>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

string ans = "";
int t;

int main()
{
	scanData();
	solveProblem();
	printAnswer();

	return 0;
}

void scanData()
{
	cin >> t;
}

void solveProblem()
{
	for(int i = 0; i < t; i++)
	{
		string tmp;
		cin >> tmp;
		ans += tmp.substr(0, 1) + tmp.substr(tmp.length()-1, 1) + "\n";
	}
}

void printAnswer()
{
	cout << ans;
}