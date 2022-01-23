#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
	stack<string> stk;
	string command;
	string answer = "";
	int n;

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
	{
		cin >> command;

		if(command == "pop"){
			if(stk.empty() != true){
				answer += stk.top() + "\n";
				stk.pop();
			}
			else
				answer += "-1\n";
		}
		else if(command == "size")
			answer += to_string(stk.size()) + "\n";
		else if(command == "empty")
			answer += to_string(stk.empty()) + "\n";
		else if(command == "top"){
			if(stk.empty() != true)
				answer += stk.top() + "\n";
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