#include <iostream>
using namespace std;

int main(void){
	int n;
	cin >> n;

	if(n == 1){
		cout << 1;
		return 0;
	}

	int ans = 0;
	for(int i = 1; i < n/2 + 1; i++){
		for(int j = i; j <= n/i; j++){
			if(i*j <= n){
				ans += 1;
			}
		}
	}

	cout << ans;



	return 0;
}