#include <iostream>
using namespace std;

int min(int a, int b)
{
	if(a < b)
		return a;
	else
		return b;
}

int arr[51] = {0, };

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);

	for(int i = 0; i < 51; i++)
		arr[i] = i;

	int cur = 1;
	int ans = 0;

	while(m--)
	{
		int tmp;
		scanf("%d", &tmp);

		int curTmp1 = cur;
		int curTmp2 = cur;
		int ans1 = 0;
		int ans2 = 0;

		while(true)
		{
			if(arr[curTmp1] == tmp)
				break;
			else
			{
				if(arr[curTmp1] != 0)
					ans1++;
				curTmp1++;
				if(curTmp1 > n)
					curTmp1 = 1;
			}
		}

		while(true)
		{
			if(arr[curTmp2] == tmp)
				break;
			else
			{
				if(arr[curTmp2] != 0)
					ans2++;
				curTmp2--;
				if(curTmp2 == 0)
					curTmp2 = n;
			}
		}

		arr[curTmp2] = 0;

		cur = curTmp2;

		while(true)
		{
			if(m == 0)
				break;
			if(arr[cur] == 0){
				cur++;
				if(cur > n)
					cur = 1;
			}
			else
				break;
		}

		ans += min(ans1, ans2);
	}

	cout << ans << endl;
}