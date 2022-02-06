#include <iostream>
using namespace std;

int main(void)
{
	int x[3];
	int y[3];
	int s;

	for(int i = 0; i < 3; i++)
		cin >> x[i] >> y[i];

	s = (x[1] - x[0]) * (y[2] - y[0]) - (y[1] - y[0]) * (x[2] - x[0]);

	if(s > 0)
		s = 1;
	else if(s < 0)
		s = -1;

	printf("%d\n", s);
}