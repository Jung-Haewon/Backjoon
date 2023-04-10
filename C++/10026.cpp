#include <iostream>
using namespace std;

void scanData();
void solveProblem();
void solveRB();
void solveRGB();
void dfsForRB(int x, int y);
void dfsForRGB(int x, int y);
void printAnswer();

char picture[102][102];
int n;

bool rbGrouped[102][102];
bool rgbGrouped[102][102];
int rbRegion = 0;
int rgbRegion = 0;

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
		for(int j = 1; j <= n; j++)
			cin >> picture[i][j];
}

void solveProblem()
{
	solveRB();
	solveRGB();
}

void solveRB()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(rbGrouped[i][j] == true)
				continue;

			dfsForRB(i, j);
			rbRegion++;
		}
	}
}

void solveRGB()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(rgbGrouped[i][j] == true)
				continue;

			dfsForRGB(i, j);
			rgbRegion++;
		}
	}
}

void dfsForRB(int x, int y)
{
	rbGrouped[x][y] = true;
	char curColor = picture[x][y];

	if(curColor == 'R' || curColor == 'G')
	{
		if(('R' == picture[x + 1][y] || 'G' == picture[x + 1][y]) && rbGrouped[x + 1][y] != true)
			dfsForRB(x + 1, y);

		if(('R' == picture[x - 1][y] || 'G' == picture[x - 1][y]) && rbGrouped[x - 1][y] != true)
			dfsForRB(x - 1, y);

		if(('R' == picture[x][y + 1] || 'G' == picture[x][y + 1]) && rbGrouped[x][y + 1] != true)
			dfsForRB(x, y + 1);

		if(('R' == picture[x][y - 1] || 'G' == picture[x][y - 1]) && rbGrouped[x][y - 1] != true)
			dfsForRB(x, y - 1);
	}
	else
	{
		if(curColor == picture[x + 1][y] && rbGrouped[x + 1][y] != true)
			dfsForRB(x + 1, y);

		if(curColor == picture[x - 1][y] && rbGrouped[x - 1][y] != true)
			dfsForRB(x - 1, y);

		if(curColor == picture[x][y + 1] && rbGrouped[x][y + 1] != true)
			dfsForRB(x, y + 1);

		if(curColor == picture[x][y - 1] && rbGrouped[x][y - 1] != true)
			dfsForRB(x, y - 1);
	}
}

void dfsForRGB(int x, int y)
{
	//cout << x << " " << y << endl;
	rgbGrouped[x][y] = true;
	char curColor = picture[x][y];

	if(curColor == picture[x + 1][y] && rgbGrouped[x + 1][y] != true)
		dfsForRGB(x + 1, y);

	if(curColor == picture[x - 1][y] && rgbGrouped[x - 1][y] != true)
		dfsForRGB(x - 1, y);

	if(curColor == picture[x][y + 1] && rgbGrouped[x][y + 1] != true)
		dfsForRGB(x, y + 1);

	if(curColor == picture[x][y - 1] && rgbGrouped[x][y - 1] != true)
		dfsForRGB(x, y - 1);
}

void printAnswer()
{
	printf("%d %d\n", rgbRegion, rbRegion);
}