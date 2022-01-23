#include <iostream>
using namespace std;

int arr[300][300];

int main(void)
{
	int n, m, k;
	cin >> n >> m;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> arr[i][j];

	cin >> k;

	for(int i = 0; i < k; i++)
	{
		int ax, ay, bx, by;
		cin >> ax >> ay >> bx >> by;

		int ans = 0;

		for(int a = ax - 1; a < bx; a++)
			for(int b = ay - 1; b < by; b++)
				ans += arr[a][b];

		cout << ans << endl;
	}




	return 0;
}