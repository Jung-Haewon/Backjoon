#include <iostream>
using namespace std;

int max(int a, int b, int c)
{
	if(a >= b && a >= c)
		return a;
	else if(b >= a && b >= c)
		return b;
	else
		return c;
}

int main(void)
{
	int sum[3] = {0, };
	int three[3] = {0, };
	int two[3] = {0, };

	int n, a, b, c;
	scanf("%d", &n);

	while(n--)
	{
		scanf("%d %d %d", &a, &b, &c);
		sum[0] += a;
		sum[1] += b;
		sum[2] += c;

		if(a == 3)
			three[0]++;
		else if(b == 3)
			three[1]++;
		else
			three[2]++;

		if(a == 2)
			two[0]++;
		else if(b == 2)
			two[1]++;
		else
			two[2]++;
	}

	int answer[ = max(sum[0], sum[1], sum[2])];

	cout << sum[0] << endl;
	cout << sum[1] << endl;
	cout << sum[2] << endl;

	if(sum[0] > sum[1] && sum[0] > sum[2])
		printf("1 %d\n", answer);
	else if(sum[1] > sum[0] && sum[1] > sum[2])
		printf("2 %d\n", answer);
	else if(sum[2] > sum[0] && sum[2] > sum[1])
		printf("3 %d\n", answer);
	else
	{
		if()


		if(three[0] > three[1] && three[0] > three[2])
			printf("1 %d\n", answer);
		else if(three[1] > sum[0] && sum[1] > sum[2])
			printf("2 %d\n", answer);
		else if(sum[2] > sum[0] && sum[2] > sum[1])
			printf("3 %d\n", answer);
		else


		printf("0 %d\n", answer);
	}

	return 0;
}