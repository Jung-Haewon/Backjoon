#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

void solveProblem();
void solveTestCase(int caseNum);
int processQuery(int l, int r);
void printAnswer();

map<int, int> dict;
int a[50001];
int T, N, Q;
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
		solveTestCase(i);
	}
}

void solveTestCase(int caseNum)
{
	int l, r;
	string testCaseAns = "";

	// 데이터 입력
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> a[i];
	cin >> Q;

	// Query 처리
	for(int i = 0; i < Q; i++)
	{
		cin >> l >> r;
		testCaseAns += to_string(processQuery(l, r)) + "\n";
	}

	answer += "Case #" + to_string(caseNum) + "\n" + testCaseAns;
}

int processQuery(int l, int r)
{
	// cout << l << " " << r << endl;
	dict.clear();


	for(int i = 1; i <= r; i++)
	{
		if(dic)
		pq.push(a[i]);
	}

	bool newTrigger = true;
	int targetNum, targetCnt;
	int squareNum = 0;

	while(pq.empty() == false)
	{
		int curNum = pq.top();
		pq.pop();

		if(newTrigger == true)
		{
			targetNum = curNum;
			targetCnt = 1;
			newTrigger = false;
		}
		else
		{
			if(targetNum != curNum)
			{
				targetNum = curNum;
				targetCnt = 1;
				newTrigger = false;
			}
			else
			{
				targetCnt++;

				if(targetCnt == targetNum)
				{
					pq.push(targetNum * targetNum);
					targetCnt = 0;
					squareNum++;
				}
			}
		}
	}

	return squareNum;
}

void printAnswer()
{
	cout << answer;
}