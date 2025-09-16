#include <iostream>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

int n, t, p;
int shirt[6];
int ans1 = 0, ans2 = 0, ans3 = 0;

int main(void)
{
	scanData();
	solveProblem();
	printAnswer();

	return 0;
}

void scanData()
{
	cin >> n;

	for(int i = 0; i < 6; i++)
		cin >> shirt[i];

	cin >> t >> p;
}

void solveProblem()
{
	for(int i = 0; i < 6; i++)
	{
		if(shirt[i] == 0)
			continue;

		if(shirt[i] % t == 0)
			ans1 += shirt[i] / t;
		else
			ans1 += shirt[i] / t + 1;
	}

	ans2 = n / p;
	ans3 = n % p;
}

void printAnswer()
{
	cout << ans1 << endl;
	cout << ans2 << " " << ans3 << endl;
}