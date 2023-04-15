#include <iostream>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

int arr[100000][3];
int n;

int main()
{
	scanData();
	solveProblem();
	printAnswer();

	return 0;
}

void scanData()
{
	cin >> n;

	for(int i = 0; i < n - 1; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;

		for(int i = 0; i < 3; i++)
			if(arr[tmp1][i] == 0)
				arr[tmp1][i] = tmp2;

		for(int i = 0; i < 3; i++)
			if(arr[tmp2][i] == 0)
				arr[tmp2][i] = tmp1;
	}
}

void solveProblem()
{
	arr[arr[1][0]

	for(int i = 2; i < n; i++)
	{

	}
}

void printAnswer()
{

}