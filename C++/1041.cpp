#include <iostream>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

int a, b, c, d, e, f;
int n;
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
	scanf("%d", &n);
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
}

void solveProblem()
{
	//주사위가 1개일 경우의 예외 처리
	if(n == 1)
	{
		int oneSide[6] = { a, b, c, d, e, f};
		int oneMax = oneSide[0];
		int sum = oneSide[0];

		for(int i = 1; i < 6; i++)
		{
			sum += oneSide[i];

			if(oneMax < oneSide[i])
				oneMax = oneSide[i];
		}

		sum -= oneMax;
		answer = sum;

		return;
	}


	//한면만 보일 경우의 최솟값 구하기
	int oneSide[6] = { a, b, c, d, e, f};
	long long oneMin = oneSide[0];

	for(int i = 1; i < 6; i++)
		if(oneMin > oneSide[i])
			oneMin = oneSide[i];


	//두면만 보일 경우의 최솟값 구하기
	int twoSide[12] = { a+b, a+c, a+d, a+e, b+c, c+e, e+d, d+b, b+f, c+f, d+f, e+f};
	long long twoMin = twoSide[0];

	for(int i = 1; i < 12; i++)
		if(twoMin > twoSide[i])
			twoMin = twoSide[i];


	//세면만 보이는 경우의 최솟값 구하기
	int threeSide[8] = { a+b+c, a+c+e, a+e+d, a+d+b, f+b+c, f+c+e, f+e+d, f+d+b};
	long long threeMin = threeSide[0];

	for(int i = 1; i < 8; i++)
		if(threeMin > threeSide[i])
			threeMin = threeSide[i];


	//정육면체에 보이는 최솟값 구하기
	answer = oneMin * (n-2) * (n-2) + 4 * oneMin * (n-2) * (n-1)
			+ 4 * twoMin * (n-2) + 4 * twoMin * (n-1)
			+ 4 * threeMin;
}

void printAnswer()
{
	cout << answer << endl;
}