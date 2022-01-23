#include <iostream>
using namespace std;
long long arr[100][10];

int main(void)
{
	arr[0][0] = 0;
	for(int i = 1; i < 10; i++)
		arr[0][i] = 1;

	for(int i = 1; i < 100; i++)
	{
		arr[i][0] = arr[i-1][1];
		arr[i][9] = arr[i-1][8];

		for(int j = 1; j < 9; j++)
			arr[i][j] = (arr[i-1][j-1] + arr[i-1][j+1]) % 1000000000;
	}

	int n;
	cin >> n;

	long long answer = 0;
	for(int i = 0; i < 10; i++)
		answer += arr[n-1][i];

	cout << answer % 1000000000 << endl;



}