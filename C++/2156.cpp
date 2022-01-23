#include <iostream>
using namespace std;

int max(int s1, int s2);

int curArr[3] = {0, };
int newArr[3] = {0, };

int main(void)
{
	int n;
	cin >> n;

	cin >> curArr[0];	
	if(n == 1){
		cout << curArr[0] << endl;
		return 0;
	}

	cin >> curArr[1];
	curArr[2] = curArr[1] + curArr[0];
	if(n == 2){
		cout << curArr[2] << endl;
		return 0;
	}

	for(int i = 2; i < n; i++)
	{
		int tmp;
		cin >> tmp;

		newArr[0] = max(newArr[0], max(curArr[1], curArr[2]));
		newArr[1] = curArr[0] + tmp;
		newArr[2] = max(newArr[1], curArr[1] + tmp);

		for(int j = 0; j < 3; j++)
			curArr[j] = newArr[j];
	}

	cout << max(curArr[0], max(curArr[1], curArr[2])) << endl;

	return 0;
}

int max(int s1, int s2)
{
	if(s1 > s2)
		return s1;
	else
		return s2;
}