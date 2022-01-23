#include <iostream>
using namespace std;

bool arr[2000002] = {false, };

int main()
{
	int n, tmp;
	cin >> n;

	for(int i = 0; i < n; i++){
		scanf("%d", &tmp);
		arr[tmp + 1000000] = true;
	}

	for(int i = 0; i < 2000002; i++){
		if(arr[i] == true)
			printf("%d\n", i - 1000000);
	}


	return 0;
}