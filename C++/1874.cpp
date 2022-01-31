#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
	int arr[100000];
	stack<int> stk;
	string answer = "+\n";

	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	stk.push(1);
	int cnt = 2;

	for(int i = 0; i < n; i++)
	{
		while(true)
		{
			if(stk.empty() == true)
			{
				stk.push(cnt);
				cnt++;
				answer += "+\n";
				continue;
			}

			if(arr[i] == stk.top())
			{
				answer += "-\n";
				stk.pop();
				break;
			}
			else if(arr[i] > stk.top())
			{
				stk.push(cnt);
				cnt++;
				answer += "+\n";
			}
			else{
				answer = "NO\n";
				break;
			}
		}

		if(answer == "NO\n")
			break;
	}

	cout << answer;
}