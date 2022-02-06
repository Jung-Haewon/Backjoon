#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int cntArr[8001] = {0, };
	int n, tmp;
	double sum = 0;
	scanf("%d", &n);
	int *arr = new int[n];



	for(int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		arr[i] = tmp;
		sum += tmp;
		cntArr[tmp + 4000]++;
	}



	int mostFreq = 0;
	int most = 0;
	int cnt = 0;

	for(int i = 0; i <= 8000; i++)
	{
		if(cntArr[i] > mostFreq)
		{
			mostFreq = cntArr[i];
			most = i - 4000;
			cnt = 1;
		}
		else if(cntArr[i] == mostFreq)
		{
			cnt++;
			if(cnt == 2)
				most = i - 4000;
		}
	}



	sort(arr, arr + n);

	printf("%.0lf\n", sum / n);
	printf("%d\n", arr[n / 2]);
	printf("%d\n", most);
	printf("%d\n", arr[n - 1] - arr[0]);

	return 0;
}