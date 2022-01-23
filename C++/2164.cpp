#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

int main(void)
{
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		q.push(i + 1);

	bool drop = true;

	while(true)
	{
		if(q.size() == 1)
			break;

		if(drop)
			q.pop();
		else
		{
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}

		drop = !drop;
	}

	cout << q.front() << endl;

	return 0;
}