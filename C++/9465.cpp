#include <iostream>
using namespace std;

void solveProblem();
void scanData();
void initData();
void solveTestCase();
int bestOfThree(int a, int b, int c);
void printAnswer();

int sticker[4][100002];
int sum[2][2];
int t, n;
int answer;

int main()
{
	solveProblem();

	return 0;
}

void solveProblem()
{
	scanf("%d", &t);

	for(int i = 0; i < t; i++)
	{
		scanData();
		solveTestCase();
		printAnswer();
	}
}

void scanData()
{
	scanf("%d", &n);
	initData();

	for(int j = 1; j <= 2; j++)
		for(int k = 1; k <= n; k++)
			scanf("%d", &sticker[j][k]);

	sum[0][0] = 0;
	sum[1][0] = 0;
	sum[0][1] = sticker[1][1];
	sum[1][1] = sticker[2][1];
}

void initData()
{
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 100002; j++)
			sticker[i][j] = 0;
}

void solveTestCase()
{
	for(int i = 2; i <= n; i++)
	{
		int next1 = bestOfThree(sum[0][0], sum[1][0], sum[1][1]) + sticker[1][i];
		int next2 = bestOfThree(sum[0][0], sum[0][1], sum[1][0]) + sticker[2][i];

		sum[0][0] = sum[0][1];
		sum[1][0] = sum[1][1];
		sum[0][1] = next1;
		sum[1][1] = next2;
	}

	if(sum[0][0] >= sum[0][1] && sum[0][0] >= sum[1][0] && sum[0][0] >= sum[1][1])
		answer = sum[0][0];
	else if(sum[0][1] >= sum[0][0] && sum[0][1] >= sum[1][0] && sum[0][1] >= sum[1][1])
		answer = sum[0][1];
	else if(sum[1][0] >= sum[0][1] && sum[1][0] >= sum[0][0] && sum[1][0] >= sum[1][1])
		answer = sum[1][0];
	else
		answer = sum[1][1];
}

int bestOfThree(int a, int b, int c)
{
	if(a >= b && a >= c)
		return a;
	else if(b >= a && b >= c)
		return b;
	else
		return c;
}

void printAnswer()
{
	cout << answer << endl;
}