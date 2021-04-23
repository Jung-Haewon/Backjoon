#include <iostream>
using namespace std;

int main(void){
	//기저조건 완성하기
	long long arr[21][21][21];
	for(int i = 0; i < 21; i++){
		for(int j = 0; j < 21; j++){
			arr[i][j][0] = 1;
			arr[i][0][j] = 1;
			arr[0][i][j] = 1;
		}
	}
	for(int i = 1; i < 21; i++){
		for(int j = 1; j < 21; j++){
			for(int k = 1; k < 21; k++){
				if(i < j && j < k)
					arr[i][j][k] = arr[i][j][k-1] + arr[i][j-1][k-1] - arr[i][j-1][k];
				else
					arr[i][j][k] = arr[i-1][j][k] + arr[i-1][j-1][k] + arr[i-1][j][k-1] - arr[i-1][j-1][k-1];
			}
		}
	}

	//문제풀이
	int a, b, c;
	cin >> a >> b >> c;
	while(a != -1 || b != -1 || c != -1){
		long long tmp;
		if(a <= 0 || b <= 0 || c <= 0)
			tmp = 1;
		else if(a > 20 || b > 20 || c > 20)
			tmp = arr[20][20][20];
		else
			tmp = arr[a][b][c];

		printf("w(%d, %d, %d) = %d\n", a, b, c, tmp);
		cin >> a >> b >> c;
	}
	return 0;
}