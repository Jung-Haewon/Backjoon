#include <iostream>
using namespace std;

void inputFunc();
void backTrack(int count, int lastNumber);
int abs(int n);

int inputArr[20][20];
bool startArr[20];
int arrSize = 0;
int best = -1;

int main(void)
{
	inputFunc();

	startArr[0] = 1;
	backTrack(1, 0); //1이 포함된 상태로 시작

	cout << best << endl;	
	return 0;
}


void inputFunc()
{
	cin >> arrSize;
	for(int i = 0; i < arrSize; i++)
		for(int j = 0; j < arrSize; j++)
			cin >> inputArr[i][j];

	for(int i = 0; i < arrSize; i++)
		startArr[i] = false;
}

void backTrack(int count, int lastNumber)
{
	if(count > arrSize / 2)
		return;


	if(count == arrSize / 2)
	{
		int start = 0;
		int link = 0;

		for(int i = 0; i < arrSize; i++)
		{
			for(int j = i + 1; j < arrSize; j++)
			{
				if(startArr[i] == false && startArr[j] == false)
					link += (inputArr[i][j] + inputArr[j][i]);
				else if(startArr[i] == true && startArr[j] == true)
					start += (inputArr[i][j] + inputArr[j][i]);
			}
		}

		int tmp = abs(start - link);
		if(tmp < best)
			best = tmp;
		else if(best < 0)
			best = tmp;
	}
	else
	{
		for(int i = lastNumber + 1; i < arrSize; i++)
		{
			for(int j = lastNumber + 1; j < i; j++)
				startArr[j] = false;
			startArr[i] = true;
			for(int j = i + 1; j < arrSize; j++)
				startArr[j] = false;
			backTrack(count + 1, i);
		}

	}
}

int abs(int n)
{
	int tmp = n;
	if(tmp < 0)
		tmp = tmp * -1;
	return tmp;
}