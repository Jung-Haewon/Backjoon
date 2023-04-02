#include <iostream>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

int arr1[100][100];
int arr2[100][100];
int ans[100][100];
int n, m;

int main()
{
	scanData();
	solveProblem();
	printAnswer();

	return 0;
}

void scanData()
{
	cin >> n >> m;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> arr1[i][j];

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> arr2[i][j];
}

void solveProblem()
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			ans[i][j] = arr1[i][j] + arr2[i][j];
}

void printAnswer()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m-1; j++)
			cout << ans[i][j] << " ";

		cout << ans[i][m-1] << endl;
	}
}