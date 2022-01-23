#include <iostream>
using namespace std;

int arr[300][2]; //[i][0]은 한칸 여유가 없는, [i][1]은 한칸 여유가 있는 최대 값

int main(void)
{
	int n;
	cin >> n;

	if(n == 0){
		cout << 0 << endl;
		return 0;
	}

	cin >> arr[0][0];
	arr[0][1] = arr[0][0];

	if(n == 1){
		cout << arr[0][0] << endl;
		return 0;
	}

	cin >> arr[1][1];
	arr[1][0] = arr[1][1] + arr[0][1];

	if(n == 2){
		cout << arr[1][0] << endl;
		return 0;
	}

	for(int i = 2; i < n; i++)
	{
		int x;
		cin >> x;

		if(arr[i-2][0] > arr[i-2][1])
			arr[i][1] = arr[i-2][0] + x;
		else
			arr[i][1] = arr[i-2][1] + x;

		if(arr[i][1] > arr[i-1][1] + x)
			arr[i][0] = arr[i][1];
		else
			arr[i][0] = arr[i-1][1] + x;
	}

	if(arr[n-1][0] > arr[n-1][1])
		cout << arr[n-1][0] << endl;
	else
		cout << arr[n-1][1] << endl;

	return 0;
}