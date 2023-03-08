#include <iostream>
#include <queue>
using namespace std;

void scanData();
void solveProblem();
queue<long long> plusQ;
queue<long long> minusQ;

int main()
{
	scanData();

	return 0;
}

void scanData()
{
	int n;
	long long tmp;

	for(int i = 0; i < 3; i++)
	{
		plusQ = queue<long long>();
		minusQ = queue<long long>();
		scanf("%d", &n);

		for(int j = 0; j < n; j++)
		{
			scanf("%lld", &tmp);

			if(tmp > 0)
				plusQ.push(tmp);
			else if(tmp < 0)
				minusQ.push(tmp);
		}
		solveProblem();
	}
}

void solveProblem()
{
	long long p, m, tmp;

	while(true)
	{
		if(plusQ.empty() || minusQ.empty())
			break;

		p = plusQ.front();
		m = minusQ.front();
		plusQ.pop();
		minusQ.pop();

		tmp = p + m;

		if(tmp > 0)
			plusQ.push(tmp);
		else if(tmp < 0)
			minusQ.push(tmp);
	}

	if(plusQ.empty() && minusQ.empty())
		cout << "0" << endl;
	else if(plusQ.empty())
		cout << "-" << endl;
	else if(minusQ.empty())
		cout << "+" << endl;
}