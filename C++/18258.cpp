#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int main(void)
{
	queue<int> stk;
	char command[7];
	int n, tmp;

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
	{
		scanf("%s", command);

		if(strcmp(command, "pop") == 0){
			if(stk.empty() != true){
				printf("%d\n", stk.front());
				stk.pop();
			}
			else 
				printf("-1\n");
		}
		else if(strcmp(command, "size") == 0)
			printf("%d\n", stk.size());
		else if(strcmp(command, "empty") == 0)
			printf("%d\n", stk.empty());
		else if(strcmp(command, "front") == 0){
			if(stk.empty() != true)
				printf("%d\n", stk.front());
			else
				printf("-1\n");
		}
		else if(strcmp(command, "back") == 0){
			if(stk.empty() != true)
				printf("%d\n", stk.back());
			else
				printf("-1\n");
		}
		else{
			scanf("%d", &tmp);
			stk.push(tmp);
		}
	}

	return 0;
}