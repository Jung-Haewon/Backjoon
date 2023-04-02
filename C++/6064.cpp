#include <iostream>
using namespace std;

void scanData();
void solveProblem();
void solveTestCase();
int gcd(int a, int b);
int lcm(int a, int b);

int t;
int m, n, x, y;
int answer;

int main()
{
	scanData();
	solveProblem();

	return 0;
}

void scanData()
{
	scanf("%d", &t);
}

void solveProblem()
{
	for(int i = 0; i < t; i++)
	{
		scanf("%d %d %d %d", &m, &n, &x, &y);
		solveTestCase();
	}
}

void solveTestCase()
{
	int mnLcm = lcm(m, n);
	//cout << mnLcm << endl;

	for(int i = x; i <= mnLcm; i += m)
	{
		if((i - 1) % n + 1 == y)
		{
			printf("%d\n", i);
			return;
		}
	}
	
	printf("-1\n");
}

int gcd(int a, int b)
{
	while(b != 0)
	{
		int tmp = a % b;
		a = b;
		b = tmp;
	}

	return a;
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}