#include <iostream>
#include <string>
using namespace std;

int m, n;
string ans = "";

void backTracking(string arr, int number){
	if(number == n){
		ans += arr + "\n";
		return;
	}

	for(int i = 1; i < m + 1; i++){
		if(arr.find(to_string(i)) == -1){
			string tmp = arr;
			tmp += " " + to_string(i);
			backTracking(tmp, number + 1);
		}
	}
}

int main(void){
	cin >> m >> n;
	
	for(int i = 1; i < m + 1; i++){
		string tmp = to_string(i);
		backTracking(tmp, 1);
	}

	cout << ans << endl;

	return 0;
}
