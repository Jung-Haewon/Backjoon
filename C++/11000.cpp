#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void scanData();
void solveProblem();

vector<pair<int, int>> arr;
int n;


int main()
{
    scanData();
    solveProblem();

    return 0;
}

void scanData()
{
	scanf("%d", &n);

	int s, t;
	for(int i = 0; i < n; i++)
	{
		scanf("%d %d", &s, &t);
		arr.push_back(pair<int, int> {s, t});
	}
	sort(arr.begin(), arr.end());
}

void solveProblem()
{
	priority_queue<int, vector<int>, greater<int>> room;
	room.push(arr[0].second);

	for(int i = 1; i < n; i++)
	{
		if(arr[i].first >= room.top())
			room.pop();

		room.push(arr[i].second);
	}

	cout << room.size() << endl;
}