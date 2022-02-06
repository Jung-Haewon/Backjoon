#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string str;
	cin >> str;

	int arr[9] = {0, };

	for(int i = 0; i < str.length(); i++)
	{
		int tmp = (int)str[i] - 48;

		if(tmp != 9)
			arr[tmp]++;
		else
			arr[6]++;
	}

	if(arr[6] % 2 == 0)
		arr[6] = arr[6] / 2;
	else
		arr[6] = arr[6] / 2 + 1;

	int answer = 0;
	for(int i = 0; i < 9; i++)
	{
		if(arr[i] > answer)
			answer = arr[i];
	}

	cout << answer << endl;

	return 0;
}