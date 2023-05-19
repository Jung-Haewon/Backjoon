#include <iostream>
#include <string>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

int lcsChart[1001][1001];
string str1, str2;

int main()
{
	scanData();
	solveProblem();
	printAnswer();

	return 0;
}

void scanData()
{
	cin >> str1;
	cin >> str2;
}

void solveProblem()
{
	for(int i = 1; i <= str1.length(); i++)
	{
		for(int j = 1; j <= str2.length(); j++)
		{
			if(str1[i - 1] == str2[j - 1])
				lcsChart[i][j] = lcsChart[i - 1][j - 1] + 1;
			else
			{
				if(lcsChart[i][j - 1] > lcsChart[i - 1][j])
					lcsChart[i][j] = lcsChart[i][j - 1];
				else
					lcsChart[i][j] = lcsChart[i - 1][j];
			}
		}
	}
}

void printAnswer()
{
	cout << lcsChart[str1.length()][str2.length()] << endl;
}