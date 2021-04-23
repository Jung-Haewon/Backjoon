#include <iostream>
using namespace std;

int main(void){
	int t, n;
	cin >> t;

	for(int i = 0; i < t; i++){
		int tmp, sum = 0;
		cin >> n;
		for(int j = 0; j < n; j++){
			cin >> tmp;
			sum += tmp;
		}
		printf("%d\n", sum);
	}

	return 0;
}