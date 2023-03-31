#include <iostream>
#include <set>
using namespace std;

bool solveTestCase();

int arr[100000];

int main()
{
	while(true)
		if(solveTestCase() != true)
			break;

	return 0;
}

bool solveTestCase()
{
	set<int> lenSet;
	int n;
	int maxArea = 0;
	scanf("%d", &n);

	if(n == 0)
		return false;

	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		lenSet.insert(arr[i]);
	}

	for(auto iter = lenSet.begin(); iter != lenSet.end(); iter++)
	{
		int curArea = 0;

		for(int i = 0; i < n; i++)
		{
			if(arr[i] < *iter)
			{
				if(maxArea < curArea)
					maxArea = curArea;
				curArea = 0;
				continue;
			}

			curArea += *iter;
		}

		if(maxArea < curArea)
			maxArea = curArea;
	}

	cout << maxArea << endl;

	return true;
}