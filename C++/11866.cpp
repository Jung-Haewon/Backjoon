#include <iostream>
using namespace std;

int arr[1000];
bool isArr[1000] = {false};
int n, k, cnt, ans;

int main(void)
{
	scanf("%d %d", &n, &k);

	for(int i = 1; i <= n; i++)
	{
		arr[i - 1] = i;
		isArr[i - 1] = true;
	}

	printf("<");

	cnt = 0;
	for(int i = 0; i < n; i++)
	{
		ans = 0;

		while(true)
		{
			if(isArr[cnt] == true)
			{
				ans++;
				if(ans == k)
				{
					isArr[cnt] = false;

					if(i != n - 1)
						printf("%d, ", arr[cnt]);
					else
						printf("%d", arr[cnt]);

					break;
				}
			}
			cnt++;

			if(cnt == n)
				cnt = 0;
		}
	}

	printf(">\n");
}