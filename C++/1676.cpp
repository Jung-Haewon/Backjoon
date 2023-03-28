#include <iostream>
using namespace std;

void dynamicProgramming();

int arr[501];

int main()
{
	dynamicProgramming();

	int n;
	cin >> n;
	cout << arr[n] << endl;

	return 0;
}

void dynamicProgramming()
{
	arr[0] = 0;

	for(int i = 1; i < 501; i++)
	{
		arr[i] = arr[i - 1];

		int tmp = i;

		while(tmp % 5 == 0)
		{
			arr[i]++;
			tmp = tmp / 5;
		}
	}
}