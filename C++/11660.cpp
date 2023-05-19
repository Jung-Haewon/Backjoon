#include <iostream>
#include <string>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

int arr[1025][1025];
int sum[1025][1025];
int n, m;
string answer = "";

int main()
{
	scanData();
	solveProblem();
	printAnswer();

	return 0;
}

void scanData()
{
	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &arr[i][j]);

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			sum[i][j] = arr[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
}

void solveProblem()
{
	for(int i = 0; i < m; i++)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		int ans = sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
		answer += to_string(ans) + "\n";
	}
}

void printAnswer()
{
	cout << answer;
}