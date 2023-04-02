#include <iostream>
using namespace std;

void scanData();
void solveProblem();

bool student[31];

int main()
{
	scanData();
	solveProblem();

	return 0;
}

void scanData()
{
	for(int i = 0; i < 30; i++)
	{
		int tmp;
		cin >> tmp;

		student[tmp] = true;
	}
}

void solveProblem()
{
	for(int i = 1; i < 31; i++)
		if(student[i] == false)
			cout << i << endl;
}