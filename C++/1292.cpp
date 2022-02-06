#include <iostream>
using namespace std;

int main(void)
{
	int arr[1000] = {0, };
	arr[0] = 1;
	int number = 2;
	int cnt = 0;
	for(int i = 1; i < 1000; i++)
	{
		arr[i] = arr[i-1] + number;
		cnt++;
		if(number == cnt)
		{
			number++;
			cnt = 0;
		}
	}

	int a, b;
	scanf("%d %d", &a, &b);

	int answer;

	if(a > 1)
		answer = arr[b - 1] - arr[a - 2];
	else
		answer = arr[b - 1];

	printf("%d\n", answer);

	return 0;
}