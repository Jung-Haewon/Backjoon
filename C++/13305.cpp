#include <iostream>
using namespace std;

long long length[100000] = {0, };
long long fuel[100000] = {0, };
long long best[100000] = {0, };

int main(void)
{
	long long n;
	scanf("%d", &n);

	for(int i = 0; i < n - 1; i++)
		scanf("%d", &length[i]);

	for(int i = 0; i < n; i++)
		scanf("%d", &fuel[i]);

	long long answer = 0;
	best[0] = fuel[0];
	long long small = best[0];

	for(int i = 0; i < n; i++)
	{
		if(fuel[i] < small)
			small = fuel[i];

		best[i] = small;
	}

	for(int i = 0; i < n - 1; i++)
		answer += length[i] * best[i];

	cout << answer << endl;
}