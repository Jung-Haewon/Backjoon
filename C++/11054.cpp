#include <iostream>
using namespace std;

int arr[1000][3];

int main(void)
{
	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> arr[i][0];
		arr[i][1] = 1;
		arr[i][2] = 1;

		for(int j = 0; j < i; j++)
		{
			if(arr[j][0] < arr[i][0] && arr[j][1] >= arr[i][1])
				arr[i][1] = arr[j][1] + 1;

			if(arr[j][0] > arr[i][0] && arr[j][2] >= arr[i][2])
				arr[i][2] = arr[j][2] + 1;

			if(arr[j][0] > arr[i][0] && arr[j][1] >= arr[i][2])
				arr[i][2] = arr[j][1] + 1;
		}
	}

	int ans = 0;

	for(int i = 0; i < n; i++)
	{
		if(arr[i][1] > ans)
			ans = arr[i][1];
		if(arr[i][2] > ans)
			ans = arr[i][2];
	}

	cout << ans << endl;





	return 0;
}