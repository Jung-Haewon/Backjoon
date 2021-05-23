#include <iostream>
using namespace std;

int main(void){
	while(true){
		int age, split, cut, leap;
		cin >> age;
		if(age == 0)
			break;

		leap = 1;
		for(int i = 0; i < age; i++){
			cin >> split >> cut;
			leap *= split;
			leap -= cut;
		}
		cout << leap << endl;
	}
	return 0;
}