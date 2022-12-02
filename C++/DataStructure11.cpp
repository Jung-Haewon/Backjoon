#include <iostream>
#include <vector>
using namespace std;

int min(int a, int b);
int cdist(int i, int j);

vector<vector<int>> cafe;
int n, k, customerNum;

int main()
{
	scanf("%d %d", &n, &k);

	for(int i = 0; i < k; i++)
	{
		scanf("%d", &customerNum);
		vector<int> customer;
		customer.push_back(customerNum);

		bool customerOutTrigger = false;

		if(cafe.size() == 0)
			customer.push_back()
		else
		{
			for(vector<int>::iterator iter = cafe.begin(); iter != cafe.end(); iter++)
			{
				if(*iter[0] == customerNum)
				{
					customerOutTrigger = true;
					cafe.erase(iter);
					break;
				}
			}
		}

		if(customerOutTrigger == true)
			continue;
		
	}
}
int min(int a, int b)
{
	if(a < b)
		return a;
	return b;
}
int cdist(int i, int j)
{
	if(min(i, j) != i)
	{
		int tmp = i;
		i = j;
		j = tmp;
	}
	return min(j - i, i + n - j);
}