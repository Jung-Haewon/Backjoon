#include <iostream>
using namespace std;

int main(void)
{
	int ans = 0;
	char tmp;

	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			scanf("%c", &tmp);

			if(tmp == 'F' && (((i+j)%2) == 0))
				ans++;
		}
		scanf("%c", &tmp);
	}

	printf("%d\n", ans);

	return 0;
}