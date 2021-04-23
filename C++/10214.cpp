#include <iostream>
using namespace std;

int main(void){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		int y = 0, k = 0, tmp;

		for(int j = 0; j < 9; j++){
			cin >> tmp;
			y += tmp;
			cin >> tmp;
			k += tmp;
		}
		if(y > k)
			cout << "Yonsei" << endl;
		else if(y < k)
			cout << "Korea" << endl;
		else
			cout << "Draw" << endl;
	}
	return 0;
}