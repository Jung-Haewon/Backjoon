#include <iostream>
using namespace std;

int coin[10] {0};

int main(void){
	int n, k, cnt = 0;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> coin[i];

	while(k != 0){
		cnt++;
		for(int i = n - 1; i >= 0; i--){
			if(k >= coin[i]){
				k -= coin[i];
				break;
			}
		}
	}
	cout << cnt;

	return 0;
}