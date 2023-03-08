#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

int dataArr[100001];
int targetArr[100001];
int sortedTargetArr[100001];
map<int, bool> answerMap;
int n, m;

int main()
{
	scanData();
	solveProblem();
	printAnswer();

	return 0;
}

void scanData()
{
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", &dataArr[i]);

	scanf("%d", &m);

	for(int i = 0; i < m; i++)
	{
		scanf("%d", &targetArr[i]);
		sortedTargetArr[i] = targetArr[i];
	}

	sort(dataArr, dataArr + n);
	sort(sortedTargetArr, sortedTargetArr + m);
}

void solveProblem()
{
	int dataIdx = 0;
	int targetIdx = 0;

	while((targetIdx < m) && (dataIdx < n))
	{
		//찾고자 하는 수가 존재하는 경우
		if(sortedTargetArr[targetIdx] == dataArr[dataIdx])
		{
			answerMap.insert({sortedTargetArr[targetIdx], true});
			targetIdx++;
		}
		//찾고자 하는 수가 존재하지 않는 경우
		else if((sortedTargetArr[targetIdx] < dataArr[dataIdx]) || dataIdx >= n)
		{
			answerMap.insert({sortedTargetArr[targetIdx], false});
			targetIdx++;
		}
		//수 찾아가는 과정
		else
			dataIdx++;
	}
}

void printAnswer()
{
	string answer = "";

	for(int i = 0; i < m; i++)
	{
		if(answerMap.find(targetArr[i])->second == true)
			answer += "1\n";
		else
			answer += "0\n";
	}

	cout << answer;
}