#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int arr[1000];
	int n, m;
	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + m);

	int ansNum;
	long long ansSum = 0;

	for(int i = m - 1; i >= 0; i--)
	{
		long long sum = 0;
		int cnt = 0;

		for(int j = m - 1; j >= 0; j--)
		{
			if(cnt == n)
				break;
			if(arr[j] < arr[i])
				break;

			sum += arr[i];
			cnt++;
		}

		if(sum >= ansSum)
		{
			ansSum = sum;
			ansNum = arr[i];
		}
	}

	printf("%d %lld\n", ansNum, ansSum);

	return 0;
}