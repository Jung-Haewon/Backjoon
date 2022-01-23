#include <iostream>
using namespace std;

int main(void)
{
	int arr[100000];
	int n;
	cin >> n;

	cin >> arr[0];
	for(int i = 1; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		if(arr[i - 1] + tmp >= tmp)
			arr[i] = arr[i - 1] + tmp;
		else
			arr[i] = tmp;
	}

	int answer = arr[0];
	for(int i = 1; i < n; i++)
		if(arr[i] > answer)
			answer = arr[i];
		
	printf("%d", answer);

}