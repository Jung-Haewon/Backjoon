#include <iostream>
using namespace std;

void backTrack(int k);

int n, m;
int* answer;

int main(void)
{
	cin >> n >> m;

	answer = new int[m];
	for(int i = 0; i < m; i++)
		answer[i] = 0;

	backTrack(0);

	delete answer;
	return 0;
}

void backTrack(int k)
{
	for(int i = 1; i <= n; i++)
	{
		answer[k] = i;

		if(k == m - 1)
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
			backTrack(k + 1);
	}
}