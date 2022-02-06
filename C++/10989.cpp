#include <iostream>
using namespace std;

int arr[10001] = {0, };

int main(void)
{
	int n, tmp;
	scanf("%d", &n);

	while(n--)
	{
		scanf("%d", &tmp);
		arr[tmp]++;
	}

	for(int i = 0; i <= 10000; i++)
		for(int j = 0; j < arr[i]; j++)
			printf("%d\n", i);

	return 0;
}