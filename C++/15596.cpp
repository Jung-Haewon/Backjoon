#include <iostream>
#include <vector>
using namespace std;

long long sum(vector<int> &a);

int main(void)
{
	int n;
	cin >> n;
	vector<int> a;

	for(int i = 0; i < n; i++)
		a.push_back(i + 1);

	cout << sum(a) << endl;

	return 0;
}

long long sum(vector<int> &a)
{
	long long ans = 0;
	for(int i = 0; i < a.size(); i++)
		ans += a[i];

	return ans;
}