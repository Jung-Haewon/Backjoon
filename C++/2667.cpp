#include <iostream>
#include <set>
using namespace std;

void scanData();
void solveProblem();
void dfs(int curX, int curY);
void printAnswer();

multiset<int> groupNums;
bool arr[27][27];
bool visited[27][27];
int n;
int groupNum;

int main()
{
	scanData();
	solveProblem();
	printAnswer();

	return 0;
}

void scanData()
{
	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			char tmp;
			cin >> tmp;

			if(tmp == '1')
				arr[i][j] = true;
		}
	}
}

void solveProblem()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(arr[i][j] == false)
				continue;
			if(visited[i][j] == true)
				continue;

			groupNum = 0;
			dfs(i, j);

			groupNums.insert(groupNum);
		}
	}
}

void dfs(int curX, int curY)
{
	visited[curX][curY] = true;
	groupNum += 1;

	if(arr[curX + 1][curY] == true && visited[curX + 1][curY] == false)
		dfs(curX + 1, curY);

	if(arr[curX - 1][curY] == true && visited[curX - 1][curY] == false)
		dfs(curX - 1, curY);

	if(arr[curX][curY + 1] == true && visited[curX][curY + 1] == false)
		dfs(curX, curY + 1);

	if(arr[curX][curY - 1] == true && visited[curX][curY - 1] == false)
		dfs(curX, curY - 1);
}

void printAnswer()
{
	cout << groupNums.size() << endl;

	for(auto iter = groupNums.begin(); iter != groupNums.end(); iter++)
		cout << *iter << endl;
}