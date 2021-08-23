#include <iostream>
using namespace std;

int** arr;
int ans[3] = {0, 0, 0};

void dq(int x, int y, int n);

int main(void){
	//입력 부분
	int n;
	cin >> n;

	arr = new int*[n];
	for(int i = 0; i < n; i++)
		arr[i] = new int[n];

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> arr[i][j];

	//문제풀이 알고리즘
	dq(0, 0, n);

	//출력 및 동적할당 해제
	for(int i = 0; i < 3; i++)
		cout << ans[i] << endl;

	for(int i = 0; i < n; i++)
		delete[] arr[i];

	return 0;
}

void dq(int x, int y, int n){
	int match = arr[x][y];
	bool trigger = false;

	//해당 구역이 모두 일치하는지를 검사
	if(n != 1){
		for(int i = x; i < x + n; i++){
			for(int j = y; j < y + n; j++){
				if(match != arr[i][j]){
					trigger = true;
					break;
				}
			}
			if(trigger == true)
				break;
		}
	}

	if(trigger == false)
		ans[match+1] += 1;
	else{
		int tmp = n/3;
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
				dq(x + i * tmp, y + j * tmp, tmp);
	}

}