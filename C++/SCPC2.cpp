#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void solveProblem();
void solveTestCase(int caseNum);
void printAnswer();

long long weight[300000];
int T, N;
string answer = "";

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
		for(int j = 0; j < N; j++)
			cin >> weight[j];

		solveTestCase(i);
	}
}

void solveTestCase(int caseNum)
{
	sort(weight, weight + N);
	long long testCaseAns = 0;

	for(int i = N-1; i > N-1-(N/4); i--)
		testCaseAns += weight[i];

	for(int i = 0; i < (N/4); i++)
		testCaseAns -= weight[i];

	testCaseAns = testCaseAns * 2;

	answer += "Case #" + to_string(caseNum) + "\n" + to_string(testCaseAns) + "\n";
}

void printAnswer()
{
	cout << answer;
}