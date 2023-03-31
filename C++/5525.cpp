#include <iostream>
#include <string>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

string s;
string p = "";
int n, m;
int answer = 0;

int main()
{
	scanData();
	solveProblem();
	printAnswer();

	return 0;
}

void scanData()
{
	cin >> n >> m >> s;
}

void solveProblem()
{
	int pLevel = -1;
	bool oTrigger = false;

	for(int i = 0; i < m; i++)
	{
		if(s[i] == 'I' && oTrigger == false)
		{
			pLevel++;
			oTrigger = true;
			continue;
		}

		if(s[i] == 'O' && oTrigger == true)
		{
			oTrigger = false;
			continue;
		}

		if(pLevel >= n)
			answer += pLevel - n + 1;

		//cout << pLevel << endl;

		pLevel = -1;
		oTrigger = false;

		if(s[i] == 'I')
		{
			pLevel++;
			oTrigger = true;
		}
	}

	if(pLevel >= n)
		answer += pLevel - n + 1;
}

void printAnswer()
{
	cout << answer << endl;
}