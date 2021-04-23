#include <iostream>
using namespace std;

int main(void){
	int n, tmp;
	cin >> n;

	while(true){
		cin >> tmp;
		if(tmp == 0)
			break;
		if(tmp % n == 0)
			printf("%d is a multiple of %d.\n", tmp, n);
		else
			printf("%d is NOT a multiple of %d.\n", tmp, n);
	}
	
	return 0;
}