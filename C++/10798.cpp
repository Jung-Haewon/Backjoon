#include <iostream>
#include <string>
using namespace std;

string str[5];
int len[5];

int main(void)
{
	int max = 0;
	for(int i = 0; i < 5; i++){
		cin >> str[i];
		len[i] = str[i].length();
		if(len[i] > max)
			max = len[i];
	}

	for(int i = 0; i < max; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if(len[j] > i)
				cout << str[j][i];
		}
	}








	return 0;
}