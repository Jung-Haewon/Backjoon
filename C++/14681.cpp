#include <iostream>
using namespace std;

int main(void)
{
	int x, y;
	cin >> x >> y;

	int ans[2][2] = {{1, 4}, {2, 3}};

	cout << ans[x<0][y<0];

	return 0;
}