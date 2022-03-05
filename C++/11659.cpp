#include <iostream>
#include <string>
using namespace std;

string ans = "";
int arr1[100001];
int arr2[100001];
int n, m, i, j;

int main(void)
{
	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; i++)
		scanf("%d", &arr1[i]);

	for(int i = 1; i <= n; i++)
		arr2[i] = arr2[i-1] + arr1[i];

	while(m--)
	{
		scanf("%d %d", &i, &j);
		ans += to_string(arr2[j] - arr2[i-1]) + "\n";
	}

	cout << ans;

	return 0;
}