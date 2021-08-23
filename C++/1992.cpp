#include <iostream>
#include <string>
using namespace std;

char arr[64][64] {0};
string ans;

void dq(int x, int y, int n){
	char tmp = arr[x][y];
	bool trigger = true;

	for(int i = x; i < x + n; i++){
		for(int j = y; j < y + n; j++){
			if(arr[i][j] != tmp){
				trigger = false;
				break;
			}
		}
	}

	if(trigger == true)
		ans += tmp;
	else{
		ans += "(";
		dq(x, y, n/2);
		dq(x, y + n/2, n/2);
		dq(x + n/2, y, n/2);
		dq(x + n/2, y + n/2, n/2);
		ans += ")";
	}
}

int main(void){
	int n;
	cin >> n;

	string tmp;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		for(int j = 0; j < n; j++){
			arr[i][j] = tmp[j];
		}
	}

	dq(0, 0, n);
	cout << ans << endl;

	return 0;
}