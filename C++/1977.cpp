#include <iostream>
using namespace std;

int square[10001] = {0, };


int main(void)
{
	int sum = 0, min = 0;
	int m, n;

	for(int i = 1; i <= 100; i++)
		square[i*i] = 1;

	cin >> m >> n;

	for(int i = m; i <= n; i++){
		if(square[i] == 1)
		{
			sum += i;
			if(min == 0)
				min = i;
		}
	}

	if(min == 0)
		cout << -1 << endl;
	else
	{
		cout << sum << endl;
		cout << min << endl;
	}

}