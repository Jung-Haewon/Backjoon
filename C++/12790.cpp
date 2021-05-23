#include <iostream>
using namespace std;

int main(void){
	int t, tmp;
	cin >> t;

	for(int i = 0; i < t; i++){
		int status[4] {0};
		for(int i = 0; i < 4; i++){
			cin >> status[i];
		}
		for(int i = 0; i < 4; i++){
			cin >> tmp;
			status[i] += tmp;
		}
		if(status[0] < 1)
			status[0] = 1;
		if(status[1] < 1)
			status[1] = 1;
		if(status[2] < 0)
			status[2] = 0;
		cout << status[0] + 5*status[1] + 2*status[2] + 2*status[3] << endl;
	}
	return 0;
}