#include <iostream>
using namespace std;

int main(void){
	int t;
	cin >> t;

	for(int i = 0; i < t; i++){
		int n, c, hak = 0;
		float g, gpa = 0;
		cin >> n;
		for(int j = 0; j < n; j++){
			cin >> c >> g;
			hak += c;
			gpa += c*g;
		}
		gpa = gpa/hak;
		printf("%d %.1f\n", hak, gpa);
	}

	return 0;
}