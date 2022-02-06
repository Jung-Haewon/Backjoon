#include <iostream>
#include <string>
using namespace std;

int arr[5000];
bool isArr[5000] = {false};
int n, k, cnt, ans;

int main(void)
{
	string answer = "<";
	scanf("%d %d", &n, &k);

	for(int i = 1; i <= n; i++)
	{
		arr[i - 1] = i;
		isArr[i - 1] = true;
	}

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
						answer += to_string(arr[cnt]) + ", ";
					else
						answer += to_string(arr[cnt]);
					break;
				}
			}
			cnt++;

			if(cnt == n)
				cnt = 0;
		}
	}

	answer += ">\n";

	cout << answer;
}