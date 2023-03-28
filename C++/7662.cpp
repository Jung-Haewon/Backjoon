#include <iostream>
#include <set>
using namespace std;

void solveProblem();
void solveTestCase();

int main()
{
	solveProblem();

	return 0;
}

void solveProblem()
{
	int t;
	cin >> t;

	for(int i = 0; i < t; i++)
		solveTestCase();
}

void solveTestCase()
{
	multiset<int> dpq;

	int k;
	cin >> k;

	for(int i = 0; i < k; i++)
	{
		char c;
		int n;

		cin >> c >> n;

		if(c == 'I')
			dpq.insert(n);
		else if(c == 'D')
		{
			if(dpq.empty() == true)
				continue;

			if(n == -1)
				dpq.erase(dpq.begin());
			else
			{
				multiset<int>::iterator iter = dpq.end();
				iter--;
				dpq.erase(iter);
			}
		}
	}

	if(dpq.empty() == true)
		cout << "EMPTY" << endl;
	else
		cout << *(dpq.rbegin()) << " " << *(dpq.begin())<< endl;
}