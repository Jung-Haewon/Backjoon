#include <iostream>
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		int r, e, c;
		cin >> r >> e >> c;

		if(r > e-c)
			printf("do not advertise\n");
		else if(r == e-c)
			printf("does not matter\n");
		else
			printf("advertise\n");
	}


	return 0;
}