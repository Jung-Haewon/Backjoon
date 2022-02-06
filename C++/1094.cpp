#include <iostream>
using namespace std;

int sqr(int num, int cnt)
{
	int ret = 1;
	for(int i = 0; i < cnt; i++)
		ret *= num;
	return ret;
}

int main(void)
{
	int n;
	scanf("%d", &n);

	int cnt = 0;
	
	for(int i = 6; i >= 0; i--)
	{
		if(n >= sqr(2, i))
		{
			n -= sqr(2, i);
			cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}