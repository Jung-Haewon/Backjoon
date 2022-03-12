#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(void)
{
	priority_queue<int, vector<int>, greater<int>> arr;
	int n, x;
	string ans = "";

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
	{
		scanf("%d", &x);

		if(x > 0)
			arr.push(x);
		else
		{
			if(arr.empty() == true)
				ans += "0\n";
			else
			{
				ans += to_string(arr.top()) + "\n";
				arr.pop();
			}
		}
	}

	cout << ans;

	return 0;
}