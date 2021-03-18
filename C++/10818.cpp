#include <iostream>
using namespace std;

int main (void)
{
	int n = 0, max, min, tmp;
	cin >> n >> tmp;
	max = tmp;
	min = tmp;

	for(int i = 0; i < n-1; i++)
	{
		cin >> tmp;
		if(max < tmp) max = tmp;
		else if(min > tmp) min = tmp;
	}

	cout << min << ' ' << max;

	return 0;
}