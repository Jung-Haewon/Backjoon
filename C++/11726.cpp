#include <iostream>
using namespace std;

int main(void)
{
	int arr[1001];
	arr[0] = 1;
	arr[1] = 1;

	for(int i = 2; i < 1001; i++)
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;

	int n;
	scanf("%d", &n);
	printf("%d\n", arr[n]);

	return 0;
}