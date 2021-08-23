#include <iostream>
using namespace std;

int main(void){
	int n;
	cin >> n;

	int* arr = new int[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	int gong = 1;
	bool endFlag = true;
	while(endFlag){
		for(int i = 0; i < n; i++){
			if(gong > arr[i]){
				endFlag = false;
				break;
			}
		}

		bool ans = true;
		for(int i = 0; i < n; i++){
			if(arr[i]%gong != 0){
				ans = false;
				break;
			}
		}

		if(ans == true)
			printf("%d\n", gong);
		gong++;
	}

	delete[] arr;
	return 0;
}