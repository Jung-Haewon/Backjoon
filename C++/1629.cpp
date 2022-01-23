#include <iostream>
using namespace std;

int main(void) {
	int a, b, c;
	scanf("%d %d %d", &a,&b, &c);

	while(b--) {
		a *= a;
		a = a % c;
	}

	printf("%d\n", a);
}