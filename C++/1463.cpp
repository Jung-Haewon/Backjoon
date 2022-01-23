#include <iostream>
using namespace std;

int min(int n1, int n2, int n3);
int arr[1000001] = { 0, };

int main(void)
{
	arr[0] = 0;
	arr[1] = 0;

	for(int i = 2; i < 1000001; i++)
	{
		int tmp1 = arr[i - 1];
		int tmp2 = tmp1;
		int tmp3 = tmp1;

		if(i % 3 == 0)
			tmp2 = arr[i/3];
		if(i % 2 == 0)
			tmp3 = arr[i/2];
		
		arr[i] = min(tmp1, tmp2, tmp3) + 1;
	}

	int n;
	cin >> n;


	cout << arr[n];




	return 0;
}

int min(int n1, int n2, int n3)
{
	if(n1 <= n2 && n1 <= n3)
		return n1;
	else if(n2 <= n1 && n2 <= n3)
		return n2;
	else
		return n3;
}