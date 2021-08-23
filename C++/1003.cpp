#include <iostream>
#include <string>
using namespace std;

string ans = "";
int fiboZero[41] = {1, 0};
int fiboOne[41] = {0, 1};

void dp(){
	for(int i = 2; i < 41; i++){
		fiboZero[i] = fiboZero[i - 1] + fiboZero[i - 2];
		fiboOne[i] = fiboOne[i - 1] + fiboOne[i - 2];
	}
}

int main(void){
	dp();
	int t, n;
	cin >> t;

	for(int i = 0; i < t; i++){
		cin >> n;
		ans += to_string(fiboZero[n]) + " " + to_string(fiboOne[n]) + "\n";
	}

	cout << ans;

	return 0;
}