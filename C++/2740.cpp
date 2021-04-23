#include <iostream>
using namespace std;

int main(void){
	int n, m;
	cin >> n >> m;

	//행렬 a 만들기
	int** a = new int* [n];
	for(int i = 0; i < n ; i++){
		a[i] = new int[m];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}

	//행렬 b 만들기
	int k;
	cin >> m >> k;
	int** b = new int* [m];
	for(int i = 0; i < m ; i++){
		b[i] = new int[k];
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < k; j++){
			cin >> b[i][j];
		}
	}

	//정답 행렬을 출력하기
	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++){
			int tmp = 0;
			for(int l = 0; l < m; l++){
				tmp += a[i][l] * b[l][j];
			}
			cout << tmp << ' ';
		}
		cout << endl;
	}

	for(int i = 0; i < n; i++)
		delete[] a[i];
	for(int i = 0; i < m; i++)
		delete[] b[i];

	return 0;
}