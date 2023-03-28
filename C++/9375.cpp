#include <iostream>
#include <map>
#include <string>
using namespace std;

void solveProblem();
void solveTestCase();

int main(void)
{
	solveProblem();
}

void solveProblem()
{
	int t;
	cin >> t;

	for(int i = 0; i < t; i++)
		solveTestCase();
}

void solveTestCase()
{
	int n;
	cin >> n;

	if(n == 0)
	{
		cout << 0 << endl;
		return;
	}

	map<string, int> clothes;

	for(int i = 0; i < n; i++)
	{
		string name, type;
		cin >> name >> type;

		if(clothes.find(type) == clothes.end())
			clothes.insert(pair<string, int>(type, 2));
		else
			clothes[type]++;

		//cout << (*clothes.find(type)).first << " " << (*clothes.find(type)).second << endl;
	}

	int answer = 1;

	for(auto iter = clothes.begin(); iter != clothes.end(); iter++)
		answer = answer * (*iter).second;

	answer--;

	cout << answer << endl;
}