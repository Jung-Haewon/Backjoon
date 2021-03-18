#include <iostream>
using namespace std;

int main(void)
{
	int c, n;
	cin >> c;

	for(int i = 0; i < c; i++)
	{
		cin >> n;
		float* list = new float[n];
		float mean = 0;

		for(int j = 0; j < n; j++)
		{
			cin >> list[j];
			mean += list[j];
		}

		mean = mean / n;
		float cnt = 0;

		for(int j = 0; j < n; j++)
		{
			if(list[j] > mean)
				cnt++;
		}

		printf("%.3f%\n", cnt/n*100);

		free(list);
	}


	return 0;
}