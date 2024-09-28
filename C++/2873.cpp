#include <iostream>
#include <string>
using namespace std;

void scanData();
void solveProblem();
void rowOdd();
void columnOdd();
void bothEven();
void printAnswer();

int r, c;
int graph[1002][1002];
string ans = "";
bool isOdd[2];

int main()
{
    scanData();
    solveProblem();
    printAnswer();

    return 0;
}

void scanData()
{
	scanf("%d %d", &r, &c);

	if(r % 2 == 1)
		isOdd[0] = true;
	if(c % 2 == 1)
		isOdd[1] = true;

	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			scanf("%d", &graph[i][j]);
}

void solveProblem()
{
	if(isOdd[0] == true)
		rowOdd();
	else if(isOdd[1] == true)
		columnOdd();
	else
		bothEven();
}

void rowOdd()
{
	bool isRight = true;

	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c - 1; j++)
		{
			if(isRight == true)
				ans += "R";
			else
				ans += "L";
		}

		if(i != r - 1)
			ans += "D";

		if(isRight == true)
			isRight = false;
		else
			isRight = true;
	}
}

void columnOdd()
{
	bool isDown = true;

	for(int j = 0; j < c; j++)
	{
		for(int i = 0; i < r - 1; i++)
		{
			if(isDown == true)
				ans += "D";
			else
				ans += "U";
		}

		if(j != c - 1)
			ans += "R";

		if(isDown == true)
			isDown = false;
		else
			isDown = true;
	}
}

void bothEven()
{

}

void printAnswer()
{
    cout << ans << endl;
}