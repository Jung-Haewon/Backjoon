#include <iostream>
using namespace std;

void scanData();
void solveProblem();
long long powerAndMod(long long x, long long y, long long z);
void printAnswer();

long long a, b, c;
long long answer;

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
	answer = powerAndMod(a, b, c);
}

long long powerAndMod(long long x, long long y, long long z)
{
	if(y == 1)
		return x % z;

	long long half = powerAndMod(x, y >> 1, z);
	long long result = (half * half) % z;

	if(y % 2 == 1)
		result = (result * x) % z;

	return result;
}


void printAnswer()
{
	cout << answer << endl;
}