#include <iostream>
using namespace std;

int main(void){
	int n = 0, m, p, max = 0;

	for(int i = 0; i < 10; i++){
		cin >> m >> p;
		n = n - m + p;
		if(n > max)
			max = n;
	}

	cout << max;
	return 0;
}