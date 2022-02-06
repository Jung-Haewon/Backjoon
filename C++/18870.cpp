#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int arr[1000000] = {0, };
	int sortArr[1000000] = {0, };
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		sortArr[i] = arr[i];
	}

	sort(sortArr, sortArr + n);

	for(int i = 0; i < n; i++){

	}







	return 0;
}