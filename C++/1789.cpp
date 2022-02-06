#include <iostream>
using namespace std;

int main(void)
{
	long long n;
	long long cnt = 1;
	long long sum = 1;

	scanf("%d", &n);

	while(true)
	{
		sum += cnt + 1;
		if(sum > n)
			break;
		cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}