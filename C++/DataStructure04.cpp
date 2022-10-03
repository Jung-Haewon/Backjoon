#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

void scanData();
void printData();
void solveProblem();

vector<vector<int>> vertex;
int c1[3] = {0, };
int c2[3] = {0, };
int k, t;
bool isReverse = false;
string answer = "";

int main()
{
	scanData();
	solveProblem();
	printData();
}
void solveProblem()
{
	for(int i = 0; i < t; i++)
	{
		int nextC1[2];
		int nextC2[2];
		int direct;

		if(isReverse == false)
			direct = 1;
		else
			direct = -1;


		//한 점에서 만난 경우의 처리
		if(c1[0] == c2[0] && c1[1] == c2[0])
			isReverse = !isReverse;

		//c1이 수평 이동을 하는 경우
		if(vertex[c1[2]][0] != vertex[(c1[2] + direct) % k][0])
		{
			if(vertex[c1[2]][0] < vertex[(c1[2] + direct) % k][0])
			{
				nextC1[0] = c1[0] + 1;
				nextC1[1] = c1[1];
			}
			else
			{
				nextC1[0] = c1[0] - 1;
				nextC1[1] = c1[1];
			}
		}
		else
		{//c1이 수직 이동을 하는 경우
			if(vertex[c1[2]][1] < vertex[(c1[2] + direct) % k][1])
			{
				nextC1[0] = c1[0];
				nextC1[1] = c1[1] + 1;
			}
			else
			{
				nextC1[0] = c1[0];
				nextC1[1] = c1[1] - 1;
			}
		}
		//c2가 수평 이동을 하는 경우
		if(vertex[c2[2]][0] != vertex[(c2[2] + direct) % k][0])
		{
			if(vertex[c2[2]][0] < vertex[(c2[2] + direct) % k][0])
			{
				nextC2[0] = c2[0] + 1;
				nextC2[1] = c2[1];
			}
			else
			{
				nextC2[0] = c2[0] - 1;
				nextC2[1] = c2[1];
			}
		}
		else
		{//c2가 수직 이동을 하는 경우
			if(vertex[c2[2]][1] < vertex[(c2[2] + direct) % k][1])
			{
				nextC2[0] = c2[0];
				nextC2[1] = c2[1] + 1;
			}
			else
			{
				nextC2[0] = c2[0];
				nextC2[1] = c2[1] - 1;
			}
		}

		//다음번에 c1, c2가 교차해서 지나가는 경우의 처리
		if(nextC1[0] == c2[0] && nextC1[1] == c2[1])
		{
			isReverse = !isReverse;
			continue;
		}

		c1[0] = nextC1[0];
		c1[1] = nextC1[1];
		c2[0] = nextC2[0];
		c2[1] = nextC2[1];

		//다음 꼭짓점에 도달 했을때의 처리
		if(c1[0] == vertex[(c1[2] + direct) % k][0] && c1[1] == vertex[(c1[2] + direct) % k][1])
			c1[2] = (c1[2] + 1) % k;
		if(c2[0] == vertex[(c2[2] - direct) % k][0] && c2[1] == vertex[(c2[2] + direct) % k][1])
			c1[2] = (c1[2] + 1) % k;
	}
}
void scanData()
{
	int circuitLength = 0;

	cin >> k;

	for(int i = 0; i < k; i++)
	{
		int x, y;
		vector<int> tmp;
		cin >> x >> y;

		tmp.push_back(x);
		tmp.push_back(y);
		vertex.push_back(tmp);

		if(i != 0)
			circuitLength += abs(tmp[i-1][0] - x) + abs(tmp[i-1][1] - y);
	}
	circuitLength += abs(tmp[0][0] - tmp[k-1][0]) + abs(tmp[0][1] - tmp[k-1][1]);

	cin >> t;
	t = circuitLength % t;
	
	c1[0] = tmp[0][0];
	c1[1] = tmp[0][1];
	c1[2] = 0;
	c2[0] = tmp[k/2][0];
	c2[1] = tmp[k/2][1];
	c2[2] = k/2;
}
void printData()
{
	answer += c1[0] + " " + c1[1] + "\n" + c2[0] + " " + c2[1];
	cout << answer << endl;
}