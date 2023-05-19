#include <iostream>
using namespace std;

void solveProblem();

int main()
{
	solveProblem();

	return 0;
}

void solveProblem()
{
	int curBest[3] = {0, 0, 0};
	int curLeast[3] = {0, 0, 0};
	int nextBest[3] = {0, 0, 0};
	int nextLeast[3] = {0, 0, 0};

	int next[3];
	int n;

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &next[0], &next[1], &next[2]);

		//최대값 구하는 과정
		if(curBest[0] > curBest[1])
			nextBest[0] = curBest[0] + next[0];
		else
			nextBest[0] = curBest[1] + next[0];

		if(curBest[0] >= curBest[1] && curBest[0] >= curBest[2])
			nextBest[1] = curBest[0] + next[1];
		else if(curBest[1] >= curBest[0] && curBest[1] >= curBest[2])
			nextBest[1] = curBest[1] + next[1];
		else
			nextBest[1] = curBest[2] + next[1];

		if(curBest[1] > curBest[2])
			nextBest[2] = curBest[1] + next[2];
		else
			nextBest[2] = curBest[2] + next[2];

		//최소값 구하는 과정
		if(curLeast[0] > curLeast[1])
			nextLeast[0] = curLeast[1] + next[0];
		else
			nextLeast[0] = curLeast[0] + next[0];

		if(curLeast[0] <= curLeast[1] && curLeast[0] <= curLeast[2])
			nextLeast[1] = curLeast[0] + next[1];
		else if(curLeast[1] <= curLeast[0] && curLeast[1] <= curLeast[2])
			nextLeast[1] = curLeast[1] + next[1];
		else
			nextLeast[1] = curLeast[2] + next[1];

		if(curLeast[1] < curLeast[2])
			nextLeast[2] = curLeast[1] + next[2];
		else
			nextLeast[2] = curLeast[2] + next[2];

		for(int i = 0; i < 3; i++)
		{
			curBest[i] = nextBest[i];
			curLeast[i] = nextLeast[i];
		}

		/*
		for(int i = 0; i < 3; i++)
			cout << curBest[i] << " ";
		cout << endl;
		for(int i = 0; i < 3; i++)
			cout << curLeast[i] << " ";
		cout << endl;
		*/
	}
	//정답 출력
	if(curBest[0] >= curBest[1] && curBest[0] >= curBest[2])
		cout << curBest[0];
	else if(curBest[1] >= curBest[0] && curBest[1] >= curBest[2])
		cout << curBest[1];
	else
		cout << curBest[2];
	
	cout << " ";

	if(curLeast[0] <= curLeast[1] && curLeast[0] <= curLeast[2])
		cout << curLeast[0];
	else if(curLeast[1] <= curLeast[0] && curLeast[1] <= curLeast[2])
		cout << curLeast[1];
	else
		cout << curLeast[2];

	cout << "\n";
}