#include <iostream>
using namespace std;

void backTrack(int k, int max);

int n, m;
int* answer;

int main(void)
{
	cin >> n >> m;

	answer = new int[m];
	for(int i = 0; i < m; i++)
		answer[i] = 0;

	backTrack(1, 1);

	delete answer;
	return 0;
}

void backTrack(int k, int max)
{
	for(int i = max; i <= n; i++)
	{
		answer[k-1] = i;

		if(k == m)
		{
			for(int j = 0; j < m; j++)
			{
				printf("%d", answer[j]);

				if(j == m - 1)
					printf("\n");
				else
					printf(" ");
			}
		}
		else
			backTrack(k + 1, i);
	}
}