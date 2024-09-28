#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

void solveProblem();
void solveTestCase(int caseNum);
// int gradientDescent();
int bruteForce(int depth, int Max, set<int> history);
void printAnswer();

int T, N, L;
int A[100000], B[100000];
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
		cin >> N >> L;
		for(int i = 0; i < N; i++)
			cin >> A[i];
		for(int i = 0; i < N; i++)
			cin >> B[i];
		solveTestCase(i);
	}
}

void solveTestCase(int caseNum)
{
	int testCaseAns = 0;
	
	// testCaseAns = gradientDescent();
	set<int> history;
	for(int i = 0; i < N; i++)
		history.insert(i);
	testCaseAns = bruteForce(0, -1, history);

	answer += "Case #" + to_string(caseNum) + "\n" + to_string(testCaseAns) + "\n";
}

// void gradientDescent()
// {
// sort(A, A + N);
// sort(B, B + N);
// 	int result = 0;
// 	// true: Our goal is to go upper number
// 	// false: Our goal is to go lower number
// 	bool upDownTrigger = true;

// 	while(true)
// 	{
// 		int Max = 0;
// 		for(int i = 0, i < N; i++)
// 			if(Max < abs(A[i]-B[i]))
// 				Max = abs(A[i]-B[i]);
// 	}

// 	return result;
// }

int bruteForce(int depth, int Max, set<int> history)
{
	// cout << depth << " " << Max << endl;
	int cnt = 0;
	set<int>::iterator iter;
	for(iter = history.begin(); iter != history.end(); iter++)
	{
		int curDiff = abs(A[depth] - B[*iter]);

		if(curDiff > L)
			continue;

		if(curDiff > Max)
			Max = curDiff;

		set<int> newSet = history;
		newSet.erase(*iter);
		int Max = bruteForce(depth + 1, Max, newSet);
	}
	return Max;
}

void printAnswer()
{
	cout << answer;
}