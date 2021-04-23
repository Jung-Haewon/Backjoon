#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main(void){
	int t;
	long long n;
	cin >> t;

	for(int i = 0; i < t; i++){
		cin >> n;
		long long tmp = 0;
		string ans = "";

		while(true){
			if(pow(2, tmp+1) <= n)
				tmp++;
			else
				break;
		}

		for(int j = tmp; j >= 0; j--){
			if(n >= pow(2, j)){
				n -= pow(2, j);
				ans = to_string(j) + ' ' + ans;
			}
		}
		cout << ans << endl;
	}
	return 0;
}