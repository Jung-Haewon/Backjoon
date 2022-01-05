#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000] = {0, };
int answer = 0;
int n;

int main(void){
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	for(int i = 0; i < n; i++)
		answer += (n - i) * arr[i];

	cout << answer << endl;



	return 0;
}