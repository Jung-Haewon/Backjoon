#include <iostream>
using namespace std;

int main(void){
	int a, b;
	int ax, ay, bx, by;
	cin >> a >> b;

	ax = (a-1)/4;
	bx = (b-1)/4;
	ay = (a-1)%4;
	by = (b-1)%4;

	cout << abs(ax-bx) + abs(ay-by);

	return 0;
}