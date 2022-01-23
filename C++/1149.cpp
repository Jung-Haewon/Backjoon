#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int n, r, g, b;

	int oldBest[3] = {0, 0, 0};
	int newBest[3] = {0, 0, 0};

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> r >> g >> b;

		if(oldBest[1] + r < oldBest[2] + r)
			newBest[0] = oldBest[1] + r;
		else
			newBest[0] = oldBest[2] + r;

		if(oldBest[0] + g < oldBest[2] + g)
			newBest[1] = oldBest[0] + g;
		else
			newBest[1] = oldBest[2] + g;

		if(oldBest[0] + b < oldBest[1] + b)
			newBest[2] = oldBest[0] + b;
		else
			newBest[2] = oldBest[1] + b;

		for(int i = 0; i < 3; i++)
			oldBest[i] = newBest[i];
	}

	sort(oldBest, oldBest + 3);
	cout << oldBest[0] << endl;

	return 0;
}