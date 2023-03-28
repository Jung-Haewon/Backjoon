#include <iostream>
using namespace std;

int arr[50001];

int main()
{
	for(int i = 1; i <= 50000; i++)
		arr[i] = 4;

	for(int i = 1; i <= 223; i++)
		arr[i*i] = 1;

	for(int i = 1; i <= 223; i++)
	{
		for(int j = i; j <= 223; j++)
		{
			if(i*i + j*j > 50000)
				break;

			if(arr[i*i + j*j] == 4)
				arr[i*i + j*j] = 2;
		}
	}

	for(int i = 1; i <= 223; i++)
	{
		for(int j = i; j <= 223; j++)
		{
			for(int k = j; k <= 223; k++)
			{
				if(i*i + j*j + k*k > 50000)
					break;

				if(arr[i*i + j*j + k*k] == 4)
					arr[i*i + j*j + k*k] = 3;
			}
		}
	}

	int n;
	cin >> n;
	cout << arr[n] << endl;

	return 0;
}