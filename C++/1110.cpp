#include <iostream>
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	int tmp = n;
	int first = 0, second = 0, third = 0;
	int cnt = 0;
	while(true)
	{
		if(tmp < 0)
		{
			first = 0;
			second = tmp;
		}
		else
		{
			first = tmp / 10;
			second = tmp % 10;
		}
		third = (first + second) % 10;
		first = second;
		second = third;
		tmp = first*10 + second;

		cnt++;
		if(tmp == n)
			break;
	}

	cout << cnt;

	return 0;
}