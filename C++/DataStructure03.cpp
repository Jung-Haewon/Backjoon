#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

void scanData(void);
void printAnswer(void);
void solveProblem(void);

int k;
vector<vector<int>> vertex;
string answer = "";

int main(void)
{
	scanData();
	solveProblem();
	printAnswer();
}
void solveProblem(void)
{
	for(int i = 0; i < 5; i++)
	{
		int query, vertexNum, time, x, y;
		cin >> query;

		while(query > vertex[k][2])
			query -= vertex[k][2];

		for(int i = 0; i < k + 1; i++)
		{
			if(query <= vertex[i][2])
			{
				vertexNum = i - 1;
				break;
			}
		}

		time = vertex[vertexNum][2];
		x = vertex[vertexNum][0];
		y = vertex[vertexNum][1];

		//수직 선분상에 존재하는 경우
		if(x - vertex[vertexNum + 1][0] == 0)
		{
			if(y - vertex[vertexNum + 1][1] < 0)
				y += query - time;
			else
				y -= query - time;
		}
		else //수평 선분상에 존재하는 경우
		{
			if(x - vertex[vertexNum + 1][0] < 0)
				x += query - time;
			else
				x -= query - time;
		}

		answer += to_string(x) + " " + to_string(y) + "\n";
	}
}
void scanData(void)
{
	cin >> k;
	int cnt = 0;

	for(int i = 0; i < k; i++)
	{
		int x, y;
		vector<int> tmpVec;
		cin >> x >> y;

		if(i != 0)
			cnt += abs(vertex[i-1][0] - x) + abs(vertex[i-1][1] - y);

		tmpVec.push_back(x);
		tmpVec.push_back(y);
		tmpVec.push_back(cnt);
		vertex.push_back(tmpVec);
	}
	vector<int> tmpVec;
	int x = vertex[0][0];
	int y = vertex[0][1];
	cnt += abs(vertex[k-1][0] - x) + abs(vertex[k-1][1] - y);
	tmpVec.push_back(x);
	tmpVec.push_back(y);
	tmpVec.push_back(cnt);
	vertex.push_back(tmpVec);
}
void printAnswer(void)
{
	cout << answer;
}