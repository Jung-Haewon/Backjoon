#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(void)
{
	queue<string> stk;
	string command;
	string answer = "";
	int n;

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
	{
		cin >> command;

		if(command == "pop"){
			if(stk.empty() != true){
				answer += stk.front() + "\n";
				stk.pop();
			}
			else
				answer += "-1\n";
		}
		else if(command == "size")
			answer += to_string(stk.size()) + "\n";
		else if(command == "empty")
			answer += to_string(stk.empty()) + "\n";
		else if(command == "front"){
			if(stk.empty() != true)
				answer += stk.front() + "\n";
			else
				answer += "-1\n";
		}
		else if(command == "back"){
			if(stk.empty() != true)
				answer += stk.back() + "\n";
			else
				answer += "-1\n";
		}
		else{
			cin >> command;
			stk.push(command);
		}
	}

	cout << answer;

	return 0;
}