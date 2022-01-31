#include <iostream>
using namespace std;

int main(void)
{
	int t, n, m;
	scanf("%d", &t);

	while(t--)
	{
		scanf("%d %d", &n, &m);

		if(m - n < n)
			n = m - n;

		int answer = 1;

		for(int i = 0; i < n; i++)
			answer = answer * (m - i) / (i + 1);

		printf("%d\n", answer);

	}


}