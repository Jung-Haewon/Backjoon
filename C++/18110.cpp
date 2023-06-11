#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

int n;
int arr[300001];
int answer;

int main()
{
	scanData();

	if(n == 0)
	{
		cout << "0" << endl;
		return 0;
	}

	solveProblem();
	printAnswer();

	return 0;
}

void scanData()
{
	scanf("%d", &n);

	if(n == 0)
		return;

	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
}

void solveProblem()
{
	sort(arr, arr + n);
	int margin = round(n * 0.15f);
	float sum = 0;

	//cout << margin << endl;

	for(int i = margin; i < n - margin; i++)
		sum += arr[i];

	answer = round(sum / (n - 2*margin));
}

void printAnswer()
{
	cout << answer << endl;
}