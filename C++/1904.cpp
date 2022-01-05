#include <iostream>
using namespace std;

int n;

long long tmp  = 0;
long long tmp1 = 1;
long long tmp2 = 2;

int main(void){
	scanf("%d", &n);

	if(n < 3)
		cout << n << endl;
	else{
		for(int i = 0; i < n - 2; i++){
			tmp = tmp2;
			tmp2 = tmp1 + tmp2;
			tmp1 = tmp;


			tmp2 = tmp2 % 15746;
			tmp1 = tmp1 % 15746;
		}
		cout << tmp2 % 15746 << endl;
	}

	return 0;
}