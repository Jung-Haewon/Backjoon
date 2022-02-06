#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int n, tmp;
	bool arr[21] = {false, };
	string command;
	string answer = "";

	int cnt = 0;

	scanf("%d", &n);

	while(n--)
	{
		cin >> command;

		if(command == "add")
		{
			scanf("%d", &tmp);
			arr[tmp] = true;
		}
		else if(command == "remove")
		{
			scanf("%d", &tmp);
			arr[tmp] = false;
		}
		else if(command == "check")
		{
			scanf("%d", &tmp);
			if(arr[tmp] == true)
				answer += "1\n";
			else
				answer += "0\n";

			cnt++;
			if(cnt > 1000)
			{
				cnt = 0;
				cout << answer;
				answer = "";
			}
		}
		else if(command == "toggle")
		{
			scanf("%d", &tmp);
			if(arr[tmp] == true)
				arr[tmp] = false;
			else
				arr[tmp] = true;
		}
		else if(command == "all")
		{
			for(int i = 1; i < 21; i++)
				arr[i] = true;
		}
		else if(command == "empty")
		{
			for(int i = 1; i < 21; i++)
				arr[i] = false;
		}
	}
	cout << answer;
}