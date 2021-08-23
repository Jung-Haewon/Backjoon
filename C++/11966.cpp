#include <iostream>
using namespace std;

int main(void){
	int n;
	cin >> n;
	bool ans = (n % 2) == 0;
	if(n == 1)
		ans = true;

	while(ans){
		n = n / 2;
		if(n < 2)
			break;
		ans = (n % 2) == 0;
	}

	if(ans == true)
		cout << 1;
	else
		cout << 0;

	return 0;
}