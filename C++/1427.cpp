#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int arr[10] = {0, };
	string str;
	cin >> str;

	for(int i = 0; i < str.length(); i++)
		arr[(int)str[i] - 48]++;

	for(int i = 9; i >= 0; i--)
		for(int j = 0; j < arr[i]; j++)
			printf("%d", i);

	printf("\n");

	return 0;
}