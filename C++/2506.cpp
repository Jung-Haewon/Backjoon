#include <iostream>
using namespace std;

int main(void){
	int n, a, s = 1, result = 0;
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> a;
		if(a == 1){
			result += s;
			s++;
		}
		else
			s = 1;
	}

	cout << result;
	return 0;
}