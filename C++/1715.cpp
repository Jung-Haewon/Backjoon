#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int arr[100000] = {0, };
	long long n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + n);

	long long sum = 0;
	long long cur = arr[0];

	for(int i = 1; i < n; i++)
	{
		cur = cur + arr[i];
		sum += cur;
	}

	printf("%d\n", sum);

	return 0;
}