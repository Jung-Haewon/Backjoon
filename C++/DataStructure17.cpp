#include <iostream>
#include <vector>
#include <string>
using namespace std;

string braceString = "";
vector<int> braceComp;

void scanCode()
{
	char curChar;

	while(true)
	{
		cin >> curChar;
		if(cin.eof() == true)
			break;

		if(curChar == '{' || curChar == '}')
			braceString += curChar;
	}
}

void calComplexity()
{
	int curComp = 0;

	for(int i = 0; i < braceString.size(); i++)
	{
		if(braceString[i] == '{')
		{
			curComp += 1;
			braceComp.push_back(curComp);
		}
		else
			curComp -= 1;
	}
}

void printBraceComp()
{
	for(int i = 0; i < braceComp.size(); i++)
		cout << braceComp[i] << " ";
	cout << endl;
}

void printAnswer()
{
	int sum = 0;
	for(int i = 0; i < braceComp.size(); i++)
		sum += braceComp[i];
	cout << sum << endl;
}

int main()
{
	scanCode();
	//cout << braceString << endl;
	calComplexity();
	//printBraceComp();
	printAnswer();

	return 0;
}
