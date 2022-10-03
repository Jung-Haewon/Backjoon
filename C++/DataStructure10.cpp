#include <iostream>
#include <string>
#define RANGE 1001
using namespace std;

void solveProblem();
void printAnswer();
int ansArr[1001] = {0, };

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
		int tmpArr[RANGE] = {0, };
		int newAnsArr[RANGE] = {0, };
		scanf("%d", &t);

		for(int j = 0; j < t; j++)
		{
			scanf("%d %d", &c, &e);
			tmpArr[e] += c;
		}

		if(i == 0)
			for(int j = 0; j < RANGE; j++)
				ansArr[j] = tmpArr[j];
		else
		{
			for(int j = 0; j < RANGE; j++)
			{
				if(tmpArr[j] == 0)
					continue;

				for(int k = 0; k < RANGE; k++)
				{
					if(ansArr[k] == 0)
						continue;

					newAnsArr[j+k] += tmpArr[j] * ansArr[k];
				}
			}

			for(int j = 0; j < RANGE; j++)
				ansArr[j] = newAnsArr[j];
		}
	}
}
void printAnswer()
{
	string answer = "\n";
	int cnt = 0;

	for(int i = RANGE - 1; i >= 0; i--)
	{
		if(ansArr[i] == 0)
			continue;

		answer += to_string(ansArr[i]) + " " + to_string(i) + "\n";
		cnt++;
	}

	answer = to_string(cnt) + answer;
	cout << answer;
}