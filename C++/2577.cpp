#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int a, b, c;
	int ans[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	cin >> a >> b >> c;

	string mul = to_string(a*b*c);

	for(int i = 0; i < mul.length(); i++)
	{
		ans[(int)mul[i]-48] += 1;
	}

	for(int i = 0; i < 10; i++)
	{
		cout << ans[i] << endl;
	}

	return 0;
}