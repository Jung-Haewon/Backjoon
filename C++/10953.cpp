#include <iostream>
using namespace std;

int main(void)
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		int a, b;
		char c;
		scanf("%d%c%d", &a, &c, &b);
		printf("%d\n", a + b);
	}




	return 0;
}