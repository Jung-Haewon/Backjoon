#include <iostream>
using namespace std;

int main(void) {
		long long a, b, c;
		cin >> a >> b >> c;

		while(b--) {
			a *= a;
			a = a % c;
		}

	cout << a << endl;
}