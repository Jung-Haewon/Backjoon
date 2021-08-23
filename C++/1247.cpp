#include <iostream>
using namespace std;

int main(void){
	int number = 0;
	for(int i = 0; i < 3; i++){
		cin >> number;
		__int128 result = 0;
		__int128 tmp;
		for(int i = 0; i < number; i++){
			cin >> tmp;
			result += tmp;
		}
		if(result > 0)
			cout << '+' << endl;
		else if(result < 0)
			cout << '-' << endl;
		else
			cout << '0' << endl;
	}

	return 0;
}