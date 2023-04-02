#include <iostream>
#include <string>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

string str;
string ans = "";

int main()
{
	scanData();
	solveProblem();
	printAnswer();

	return 0;
}

void scanData()
{
	cin >> str;
}

void solveProblem()
{
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] >= 97)
			ans += str[i] - 32;
		else
			ans += str[i] + 32;
	}
}

void printAnswer()
{
	cout << ans << endl;
}