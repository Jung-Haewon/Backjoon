#include <iostream>
#include <cmath>
using namespace std;

void input();

int n, r, c;
long long ans;

int main(void)
{
	input();

	for(int cnt = n; cnt > 0; cnt--)
	{
		long long sectorSum = pow(2, cnt) * pow(2, cnt);
		long long sectorHalf = pow(2, cnt) / 2;

		int sector;

		if(r < sectorHalf && c < sectorHalf)
			sector = 0;
		else if(r < sectorHalf && c >= sectorHalf)
		{
			sector = 1;
			c -= sectorHalf;
		}
		else if(r >= sectorHalf && c < sectorHalf)
		{
			sector = 2;
			r -= sectorHalf;
		}
		else
		{
			sector = 3;
			c -= sectorHalf;
			r -= sectorHalf;
		}

		ans += sectorSum / 4 * sector;
	}

	printf("%d\n", ans);
}

void input()
{
	scanf("%d %d %d", &n, &r, &c);
	ans = 0;
}