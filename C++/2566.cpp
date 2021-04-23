#include <iostream>
using namespace std;

int main(void){
	int x, y, n, max = 0;
	for(int i = 1; i < 10; i++){
		for(int j = 1; j < 10; j++){
			cin >> n;
			if(n > max){
				max = n;
				x = i;
				y = j;
			}
		}
	}
	printf("%d\n%d %d", max, x, y);
	return 0;
}