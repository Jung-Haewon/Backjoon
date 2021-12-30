#include <iostream>
using namespace std;

int abs(int n);

int main(void)
{
	int score[10];
	int bestSum = 0;

	for(int i = 0; i < 10; i++)
		cin >> score[i];

	for(int i = 0; i < 10; i++)
		if(abs(100 - bestSum) >= abs(100 - bestSum - score[i]))
			bestSum += score[i];
		else
			break;

	cout << bestSum << endl;

	return 0;
}

int abs(int n)
{
	int returnNum = n;
	if(n < 0)
		returnNum = returnNum * -1;
	return returnNum;
}