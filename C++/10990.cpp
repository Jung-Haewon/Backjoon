#include <iostream>
using namespace std;

int main(void){
	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		for(int j = 1; j < n-i; j++)
			cout << " ";
		cout << "*";
		if(i != 0){
			for(int j = 0; j < 2*i-1; j++)
				cout << " ";
			cout << "*";
		}
		if(i != n-1)
			cout << endl;
	}


	return 0;
}