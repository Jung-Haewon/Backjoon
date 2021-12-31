#include <iostream>
using namespace std;

int arr[15];
int sumArr[15];
int minArr[15];

int count = 0;
int n;

void backTrack(int q);

int main(void)
{
	cin >> n;
	backTrack(0);
	cout << count << endl;

	return 0;
}

void backTrack(int q)
{
	for(int i = 0; i < n; i++)
	{
		int sumTmp = i + q;
		int minTmp = i - q;
		bool trigger = true;

		for(int j = 0; j < q; j++)
		{
			if(trigger == false)
				break;

			if(sumTmp == sumArr[j])
				trigger = false;
			if(minTmp == minArr[j])
				trigger = false;
			if(i == arr[j])
				trigger = false;
		}

		if(trigger == true)
		{
			if(q == n - 1)
				count++;
			else
			{
				arr[q] = i;
				sumArr[q] = sumTmp;
				minArr[q] = minTmp;
				backTrack(q + 1);
			}
		}
	}
}