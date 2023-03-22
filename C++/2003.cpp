#include <iostream>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

int n;
int m;
int arr[10001]; 
int answer = 0;

int main()
{
	scanData();
	solveProblem();
	printAnswer();
}

void scanData()
{
	scanf("%d %d", &n, &m);
	arr[0] = 0;

	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
		arr[i] = arr[i] + arr[i-1];
	}
}

void solveProblem()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = n; j >= i; j--)
		{
			int tmp = arr[j] - arr[i-1];

			if(tmp < m)
				break;

			if(tmp == m)
			{
				//cout << i << " " << j << endl;
				answer++;
				break;
			}
		}
	}
}

void printAnswer()
{
	cout << answer << endl;
}