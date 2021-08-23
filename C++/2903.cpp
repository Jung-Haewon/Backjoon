#include <iostream>
using namespace std;

int main(void){
	int n;
	cin >> n;
	int start = 2;
	for(int i = 0; i < n; i++){
		start = start + start - 1;
	}

	cout << start*start << endl;

	return 0;
}