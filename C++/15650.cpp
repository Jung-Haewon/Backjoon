#include <iostream>
#include <string>
using namespace std;

string ans = "";
int n, m;

void backTracking(int num, int cnt, string cur){
	if(cnt == m){
		ans += cur + "\n";
		return;
	}
	else if(num + (m - cnt) > n)
		return;
	else{
		string tmp;
		for(int i = num + 1; i < n + 1; i++){
			tmp = cur + " " + to_string(i);
			backTracking(i, cnt + 1, tmp);
		}
	}
}

int main(void){
	cin >> n >> m;

	for(int i = 1; i < n + 1; i++){
		backTracking(i, 1, to_string(i));
	}

	cout << ans;

	return 0;
}