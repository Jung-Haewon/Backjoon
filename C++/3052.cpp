#include <iostream>
using namespace std;

int main(void)
{
	int ans = 0;
	int b[43] {0};

	for(int i = 0; i < 10; i++)
	{
		int a;
		cin >> a;
		b[a % 42] = 1;
	}

	for(int i = 0; i < 43; i++)
	{
		ans += b[i];
	}

	cout << ans << endl;

	return 0;
}