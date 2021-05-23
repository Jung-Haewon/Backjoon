#include <iostream>
using namespace std;

int main(void){
	int n, l, d;
	cin >> n >> l >> d;

	int song, next = -1, bell = 0;
	for(int i = 0; i < n; i++){
		song = next + l;
		next = song + 5;
		while(bell < next){
			bell += d;
			if(bell > song && bell <= next){
				cout << bell;
				return 0;
			}
		}
	}
	while(bell < song){
		bell += d;
	}

	cout << bell;


	return 0;
}