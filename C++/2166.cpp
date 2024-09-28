#include <iostream>
#include <cmath>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

long long arr[100000][2];
int n;
double ans = 0;

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
		scanf("%lld %lld", &arr[i][0], &arr[i][1]);
}

void solveProblem()
{
	for(int i = 0; i < n - 1; i++)
		ans += (arr[i][0] * arr[i + 1][1]) - (arr[i + 1][0] * arr[i][1]);
	ans += arr[n-1][0] * arr[0][1] - arr[0][0] * arr[n-1][1];
	ans = fabs(ans);
	ans = ans / 2;
}

void printAnswer()
{
	cout << fixed;
	cout.precision(1);
	cout << ans << endl;
}