#include <iostream>
using namespace std;

int main(void)
{
	int n, max = 0;
	cin >> n;

	float* grade = new float[n];

	for(int i = 0; i < n; i++)
	{
		cin >> grade[i];
		if(grade[i] > max) max = grade[i];
	}

	for(int i = 0; i < n; i++)
	{
		grade[i] = grade[i]/max*100;
	}

	float ans = 0;
	for(int i = 0; i < n; i++)
	{
		ans += grade[i];
	}

	cout << ans/n << endl;

	return 0;
}