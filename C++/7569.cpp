#include <iostream>
#include <set>
#include <tuple>
using namespace std;

void scanData();
int solveProblem();
void bfs();
void printAnswer(int ans);

int boxes[102][102][102];
int h, n, m;
int unripeTomato = 0;
int newUnripeTomato;
int day = 0;
set<tuple<int, int, int>> curRipeTomato;
set<tuple<int, int, int>> newRipeTomato;

int main()
{
	scanData();
	int ans = solveProblem();
	printAnswer(ans);

	return 0;
}

void scanData()
{
	scanf("%d %d %d", &m, &n, &h);

	for(int i = 0; i < 102; i++)
		for(int j = 0; j < 102; j++)
			for(int k = 0; k < 102; k++)
				boxes[i][j][k] = -1;

	for(int i = 1; i <= h; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			for(int k = 1; k <= m; k++)
			{
				scanf("%d", &boxes[i][j][k]);

				if(boxes[i][j][k] == 1)
					curRipeTomato.insert(make_tuple(i, j, k));
				else if(boxes[i][j][k] == 0)
					unripeTomato++;
			}
		}
	}
}

int solveProblem()
{
	newUnripeTomato = unripeTomato;

	while(true)
	{
		//cout << "unripe: " << unripeTomato << endl;
		if(unripeTomato == 0)
			break;

		day++;

		bfs();

		curRipeTomato = newRipeTomato;
		newRipeTomato.clear();

		if(newUnripeTomato == unripeTomato)
		{
			day--;
			return -1;
		}

		unripeTomato = newUnripeTomato;
	}

	return 0;
}

void bfs()
{
	if(curRipeTomato.empty() == true)
		return;

	int x, y, z;
	tie(x, y, z) = *(curRipeTomato.begin());
	curRipeTomato.erase(curRipeTomato.begin());
	//printf("%d %d %d\n", x, y, z);

	if(boxes[x][y][z+1] == 0)
	{
		newRipeTomato.insert(make_tuple(x, y, z+1));
		boxes[x][y][z+1] = 1;
		newUnripeTomato--;
	}
	if(boxes[x][y][z-1] == 0)
	{
		newRipeTomato.insert(make_tuple(x, y, z-1));
		boxes[x][y][z-1] = 1;
		newUnripeTomato--;
	}

	if(boxes[x][y+1][z] == 0)
	{
		newRipeTomato.insert(make_tuple(x, y+1, z));
		boxes[x][y+1][z] = 1;
		newUnripeTomato--;
	}
	if(boxes[x][y-1][z] == 0)
	{
		newRipeTomato.insert(make_tuple(x, y-1, z));
		boxes[x][y-1][z] = 1;
		newUnripeTomato--;
	}

	if(boxes[x+1][y][z] == 0)
	{
		newRipeTomato.insert(make_tuple(x+1, y, z));
		boxes[x+1][y][z] = 1;
		newUnripeTomato--;
	}
	if(boxes[x-1][y][z] == 0)
	{
		newRipeTomato.insert(make_tuple(x-1, y, z));
		boxes[x-1][y][z] = 1;
		newUnripeTomato--;
	}

	bfs();
}

void printAnswer(int ans)
{
	if(ans == -1)
		printf("-1\n");
	else
		printf("%d\n", day);
}