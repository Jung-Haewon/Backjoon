#include <iostream>
#include <string>
using namespace std;

void solveProblem();
void solveTestCase(int caseNum);
void printAnswer();

int T, N;
string input, answer = "";

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solveProblem();
	printAnswer();

	return 0;
}

void solveProblem()
{
	cin >> T;

	for(int i = 1; i <= T; i++)
	{
		cin >> N;
		cin >> input;
		solveTestCase(i);
	}
}

void solveTestCase(int caseNum)
{
	int testCaseAns = 0;

	for(int i = 0; i < N-1; i++)
	{
		if(input[i] == 'B')
			continue;

		if(input[i+1] == 'A')
			testCaseAns += 2;
		else if(i < N-2 && input[i+2] == 'A')
			testCaseAns += 1;
	}

	answer += "Case #" + to_string(caseNum) + "\n" + to_string(testCaseAns) + "\n";
}

void printAnswer()
{
	cout << answer;
}