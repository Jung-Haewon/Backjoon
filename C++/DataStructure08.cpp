#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solveProblem();
void printAnswer();
int arr[201] = {0, };

int main()
{
	solveProblem();
	printAnswer();

	return 0;
}
void solveProblem()
{
	int n, t, c, e;
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
	{
		scanf("%d", &t);

		for(int j = 0; j < t; j++)
		{
			scanf("%d %d", &c, &e);
			arr[e + 100] += c;
		}
	}
}
void printAnswer()
{
	string answer = "\n";
	int cnt = 0;

	for(int i = 200; i >= 0; i--)
	{
		if(arr[i] == 0)
			continue;

		answer += to_string(arr[i]) + " " + to_string(i-100) + "\n";
		cnt++;
	}

	if(cnt == 0)
	{
		printf("0 0\n");
		return;
	}

	answer = to_string(cnt) + answer;
	cout << answer;
}