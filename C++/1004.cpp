#include <iostream>
#include <cmath>

int main(void)
{
	int t, n, x, y, r;
	int answer;
	bool trigger;
	int a[2];
	int b[2];

	scanf("%d", &t);

	for(int i = 0; i < t; i++)
	{
		answer = 0;

		scanf("%d %d %d %d", &a[0], &a[1], &b[0], &b[1]);
		scanf("%d", &n);

		for(int j = 0; j < n; j++)
		{
			trigger = false;
			scanf("%d %d %d", &x, &y, &r);

			if(pow(a[0] - x, 2) + pow(a[1] - y, 2) < r*r)
				trigger = !trigger;


			if(pow(b[0] - x, 2) + pow(b[1] - y, 2) < r*r)
				trigger = !trigger;

			if(trigger == true)
				answer++;
		}

		printf("%d\n", answer);
	}



	return 0;
}