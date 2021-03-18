#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		int ans = 0, cnt = 1;

		for(int j = 0; j < tmp.length(); j++)
		{
			if(tmp[j]=='O')
			{
				ans += cnt;
				cnt++;
			}
			else
				cnt = 1;

		}

		cout << ans << endl;
	}

	return 0;
}