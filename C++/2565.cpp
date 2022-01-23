#include <iostream>
using namespace std;

int min(int n1, int n2);
int max(int n1, int n2);

int arr[100][2];
bool cross[100][100];
int num[100] = {0, };
int answer = 0;
int n;

int main(void)
{
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;

		arr[i][0] = min(tmp1, tmp2);
		arr[i][1] = max(tmp1, tmp2);
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(arr[i][0] < arr[j][1] && arr[i][1] > arr[j][0])
			{
				cross[i][j] = true;
				cross[j][i] = true;
				num[i]++;
				num[j]++;
			}
		}
	}

	//검사를 위해 넣은 문장
	/*
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << cross[i][j] << " ";
		}
		cout << endl;
	}
	*/


	while(true)
	{
		bool trigger = true;
		for(int i = 0; i < n; i++)
		{
			if(num[i] != 0)
			{
				trigger = false;
				break;
			}
		}

		if(trigger == true)
			break;

		int bestNum = 0;
		int best = 0;
		for(int i = 0; i < n; i++)
		{
			if(num[i] > best)
			{
				best = num[i];
				bestNum = i;
			}
		}

		for(int i = 0; i < n; i++)
		{
			if(cross[bestNum][i] == true)
			{
				cross[bestNum][i] = false;
				cross[i][bestNum] = false;
				num[bestNum]--;
				num[i]--;
			}
		}

		answer++;
	}

	cout << answer << endl;


	return 0;
}

int min(int n1, int n2)
{
	if(n1 < n2)
		return n1;
	else
		return n2;
}

int max(int n1, int n2)
{
	if(n1 > n2)
		return n1;
	else
		return n2;
}