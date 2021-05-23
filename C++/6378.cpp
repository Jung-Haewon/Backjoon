#include <iostream>
#include <string>
using namespace std;

int main(void){
	string n;

	while(true){
		cin >> n;

		if(n == "0")
			break;

		int tmp;
		while(true){
			tmp = 0;
			for(int i = 0; i < n.length(); i++){
				tmp += (int)n[i]-48;
			}
			n = to_string(tmp);
			if(tmp < 10)
				break;
		}
		cout << n << endl;
	}
	return 0;
}