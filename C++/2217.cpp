#include <iostream>
#include <algorithm>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

int arr[100000];
int n;
int answer = 0;

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

	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + n);
}

void solveProblem()
{
	int newAnswer;

	for(int i = 0; i < n; i++)
	{
		newAnswer = arr[i] * (n - i);

		if(newAnswer > answer)
			answer = newAnswer;
	}
}

void printAnswer()
{
	cout << answer << endl;
}