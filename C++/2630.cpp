#include <iostream>
using namespace std;

void process(int** arr, int& w, int& b, int x, int y, int n);

int main(void){
	//변수 초기화및 입력
	int w = 0, b = 0, n;
	cin >> n;

	int** arr = new int* [n];
	for(int i = 0; i < n; i++)
		arr[i] = new int[n];

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> arr[i][j];

	process(arr, w, b, 0, 0, n);
	printf("%d\n%d", w, b);

	for(int i = 0; i < n; i++)
		delete[] arr[i];

	return 0;
}

void process(int** arr, int& w, int& b, int x, int y, int n){
	int first = arr[x][y];
	bool equal = true;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(arr[x+i][y+j] != first){
				equal = false;
				break;
			}
		}
		if(equal == false)
			break;
	}

	if(equal == true){
		if(first == 0)
			w++;
		else
			b++;
	}
	else{
		int half = n/2;
		process(arr, w, b, 		x,			y, 			half);
		process(arr, w, b, 		x + half, 	y, 			half);
		process(arr, w, b, 		x, 			y + half, 	half);
		process(arr, w, b, 		x + half, 	y + half, 	half);
	}
}