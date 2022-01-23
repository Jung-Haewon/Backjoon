#include <iostream>
using namespace std;

int arr[1001][2];

int main(void)
{
	arr[0][0] = 0;
	arr[0][1] = 0;

	int n;
	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i][0];
		arr[i][1] = 0;

		for(int j = 0; j < i; j++)
		{
			if(arr[j][0] < arr[i][0] && arr[j][1] + 1 > arr[i][1])
				arr[i][1] = arr[j][1] + 1;
		}
	}

	int answer = 0;
	for(int i = 0; i <= n; i++)
		if(answer < arr[i][1])
			answer = arr[i][1];

	cout << answer << endl;




}