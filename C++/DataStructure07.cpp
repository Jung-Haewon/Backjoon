#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void scanData(void);
void printData(void);
void solveProblem(void);
int findColumnVec(int num);
bool compare(vector<int> a, vector<int> b);

vector<vector<int>> columnVec;
int n;

int main(void)
{
	scanData();
	solveProblem();
	printData();
}
void scanData(void)
{
	cin >> n;

	int cnt = 1;
	while(cnt <= n)
	{
		int tmp1, tmp2;
		cin >> tmp1;

		if(tmp1 == 0)
		{
			cin >> tmp2;
			cnt += tmp2;
		}
		else
		{
			while(tmp1 != 0) 
			{
				int i = findColumnVec(tmp1);

				if(i == -1)
				{
					vector<int> tmpVec;
					tmpVec.push_back(tmp1);
					tmpVec.push_back(cnt);
					columnVec.push_back(tmpVec);
				}
				else
					columnVec[i].push_back(cnt);
				cin >> tmp1;
			}
			cnt++;
		}
	}
}
void printData(void)
{
	string answer = to_string(n) + "\n";
	int cnt = 1;

	for(int i = 0; i < columnVec.size(); i++)
	{
		if(cnt != columnVec[i][0])
		{
			answer += "0 " + to_string(columnVec[i][0] - cnt) + "\n";
			cnt = columnVec[i][0];
		}
		for(int j = 1; j < columnVec[i].size(); j++)
			answer += to_string(columnVec[i][j]) + " ";

		answer += "0\n";
		cnt++;
	}
	
	if(columnVec.back()[0] != n)
		answer += "0 " + to_string(n - columnVec.back()[0]) + "\n";

	cout << answer;
}
void solveProblem(void)
{
	sort(columnVec.begin(), columnVec.end(), compare);
}
int findColumnVec(int num)
{
	for(int i = 0; i < columnVec.size(); i++)
		if(columnVec[i][0] == num)
			return i;

	return -1;
}
bool compare(vector<int> a, vector<int> b)
{
	return a[0] < b[0];
}