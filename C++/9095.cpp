#include <iostream>
using namespace std;

int main(void)
{
	int arr[11];
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;

	for(int i = 4; i < 11; i++)
		arr[i] = arr[i-1] + arr[i-2] + arr[i-3];

	int t, n;
	scanf("%d", &t);

	while(t--)
	{
		scanf("%d", &n);
		printf("%d\n", arr[n]);
	}

	return 0;
}