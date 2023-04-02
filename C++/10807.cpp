#include <iostream>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

int arr[100];
int n, v;
int ans = 0;

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

	for(int i = 0; i < n; i++)
		cin >> arr[i];

	cin >> v;
}

void solveProblem()
{
	for(int i = 0; i < n; i++)
		if(arr[i] == v)
			ans++;
}

void printAnswer()
{
	cout << ans << endl;
}