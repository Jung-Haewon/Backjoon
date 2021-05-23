#include <iostream>
#include <string>
using namespace std;

int main(void){
	string number;
	cin >> number;
	while(number != "0"){
		int ans = 1;
		ans += number.length();
		for(int i = 0; i < number.length(); i++){
			if(number[i] == '1')
				ans += 2;
			else if(number[i] == '0')
				ans += 4;
			else
				ans += 3;
		}
		cout << ans << endl;
		cin >> number;
	}



	return 0;
}