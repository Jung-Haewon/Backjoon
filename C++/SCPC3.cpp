#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solveProblem();
void solveTestCase(int caseNum);
int dfs(int node1, int node2);
void printAnswer();

vector<vector<int>> graph;
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
		graph.clear();
		graph = vector<vector<int>>(N+1);

		solveTestCase(i);
	}
}

void solveTestCase(int caseNum)
{
	int testCaseAns = 0;
	int first = -1, second = -1;
	int node1, node2, gap;

	// 간선 데이터 입력 처리
	// 이와 동시에, 원형 연결 이외에 다른 간선을 가지는 노드 2개 탐색
	for(int i = 0; i < N+1; i++)
	{
		cin >> node1 >> node2;

		graph[node1].push_back(node2);
		graph[node2].push_back(node1);

		if(graph[node1].size() == 3)
		{
			if(first == -1)
				first = node1;
			else
				second = node1;
		}
		if(graph[node2].size() == 3)
		{
			if(first == -1)
				first = node2;
			else
				second = node2;
		}
	}

	// cout << "This is Edge of Test" << caseNum << endl;
	// for(int i = 1; i < graph.size(); i++)
	// {
	// 	cout << i << ": ";
	// 	for(int j = 0; j < graph[i].size(); j++)
	// 		cout << graph[i][j] << ", ";
	// 	cout << endl;
	// }
	// cout << first << " " << second << endl << endl;

	// 해당 노드들을 제외하고 남은
	// 두개의 Subgraph(순환하지 않으므로 chain이라 해도 좋을듯)의 길이 중 하나를 구함
	// 만약 원형 간선 == 추가 간선인 경우 별도 처리
	int duplicateCnt = 0;
	for(int i = 0; i < 3; i++)
		if(graph[first][i] == second)
			duplicateCnt++;
	// cout << duplicateCnt << endl;
	if(duplicateCnt == 2)
		gap = -1;
	else
		gap = dfs(first, second);

	// cout << "gap: " << gap << endl;

	// Combination(gap, 2) + Combination(N-gap, 2)의 값을 구함
	if(gap == -1)
		testCaseAns = (N-1) * (N-2) / 2;
	else
		testCaseAns = ((gap) * (gap-1) / 2) + ((N-gap) * (N-gap-1) / 2);

	answer += "Case #" + to_string(caseNum) + "\n" + to_string(testCaseAns) + "\n";
}

int dfs(int node1, int node2)
{
	int prevNode = node1;
	int curNode;
	int length = 1;

	for(int i = 0; i < 3; i++)
		if(graph[node1][i] != node2)
			curNode = graph[node1][i];

	for(int i = 0; i < 300001; i++)
	{
		// cout << prevNode << " " << curNode << endl;

		if(curNode == node2)
			break;

		if(graph[curNode][0] != prevNode)
		{
			prevNode = curNode;
			curNode = graph[curNode][0];
		}
		else
		{
			prevNode = curNode;
			curNode = graph[curNode][1];
		}

		length++;
	}

	return length;
}

void printAnswer()
{
	cout << answer;
}