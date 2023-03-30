#include <iostream>
using namespace std;

short arr[50001];

int main()
{
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
		arr[i] = 4;

	for(int i = 1; i <= 223; i++)
		arr[i*i] = 1;

	for(int i = 1; i <= 223; i++)
	{
		for(int j = i; j <= 223; j++)
		{
			if(i*i + j*j > n)
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
				if(i*i + j*j + k*k > n)
					break;

				if(arr[i*i + j*j + k*k] == 4)
					arr[i*i + j*j + k*k] = 3;
			}
		}
	}

	printf("%d\n", arr[n]);

	return 0;
}