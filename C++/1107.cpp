#include <iostream>
#include <string>
#include <set>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

set<char> errorBtn;
string num;
int n, m;
int answer;

int main()
{
	scanData();
	solveProblem();
	printAnswer();

	return 0;
}

void scanData()
{
	scanf("%d", &n);
	scanf("%d", &m);
	num = to_string(n);

	for(int i = 0; i < m; i++)
	{
		char tmp;
		cin >> tmp;

		errorBtn.insert(tmp);
	}
}

void solveProblem()
{
	answer = abs(n - 100);

	for(int i = 0; i < 1000001; i++)
	{
		string tmp = to_string(i);
		bool skipTrigger = false;
		
		for(int j = 0; j < tmp.length(); j++)
		{
			if(errorBtn.find(tmp[j]) != errorBtn.end())
			{
				skipTrigger = true;
				break;
			}
		}

		if(skipTrigger == true)
			continue;

		int newMin = tmp.length() + abs(i - n);

		if(newMin < answer)
			answer = newMin;
	}
}

void printAnswer()
{
	cout << answer << endl;
}