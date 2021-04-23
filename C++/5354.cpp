#include <iostream>
using namespace std;

void drawJbox(int n);

int main(void){
	int t, n;
	cin >> t;

	for(int i = 0; i < t; i++){
		cin >> n;
		drawJbox(n);
	}
	return 0;
}

void drawJbox(int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i != 0 && i != n-1 && j != 0 && j != n-1)
				cout << 'J';
			else
				cout << '#';
		}
		cout << endl;
	}
	cout << endl;
}