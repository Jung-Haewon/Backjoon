#include <iostream>
using namespace std;

long long fibo[91];

int main(void)
{
	fibo[0] = 0;
	fibo[1] = 1;

	for(int i = 2; i <= 90; i++)
		fibo[i] = fibo[i-1] + fibo[i-2];

	int n;
	cin >> n;
	cout << fibo[n];


	return 0;
}
