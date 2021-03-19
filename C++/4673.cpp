#include <iostream>
#include <string>
using namespace std;

int selfNumber(int n)
{
	int ans = n;
	string number = to_string(n);

	for(int i = 0; i < number.length(); i++)
	{
		ans += ((int) number[i])-48;
	}

	return ans;
}

int main(void)
{
	int ans[10001] = {0};

	for(int i = 1; i < 10000; i++)
	{
		int tmp = i;
		if(ans[i] != 1)
		{
			while(1)
			{
				tmp = selfNumber(tmp);
				if(tmp > 10000)
					break;
				if(ans[tmp] == 0)
					ans[tmp] = 1;
			}
		}
	}

	for(int i = 1; i < 9999; i++)
	{
		if(ans[i] == 0)
			printf("%d\n", i);
	}

	return 0;
}

