#include <iostream>
#include <string>
using namespace std;

void solveProblem();
void solveTestCase();
void cubeInit();
void turnUp(char direction);
void turnDown(char direction);
void turnFront(char direction);
void turnBack(char direction);
void turnLeft(char direction);
void turnRight(char direction);
void turnSide(char direction, int sideNum);
void printAnswer();

char cube[6][3][3];
char initColor[6] = {'w', 'y', 'r', 'o', 'g', 'b'};

int main()
{
	solveProblem();

	return 0;
}

void solveProblem()
{
	int t;
	cin >> t;

	for(int i = 0; i < t; i++)
		solveTestCase();
}

void solveTestCase()
{
	cubeInit();
	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		char side, direction;
		cin >> side >> direction;

		switch(side)
		{
		case 'U':
			turnUp(direction);
			break;
		case 'D':
			turnDown(direction);
			break;
		case 'F':
			turnFront(direction);
			break;
		case 'B':
			turnBack(direction);
			break;
		case 'L':
			turnLeft(direction);
			break;
		case 'R':
			turnRight(direction);
			break;
		}
	}

	printAnswer();
}

void cubeInit()
{
	for(int i = 0; i < 6; i++)
		for(int j = 0; j < 3; j++)
			for(int k = 0; k < 3; k++)
				cube[i][j][k] = initColor[i];
}

void turnUp(char direction)
{
	if(direction == '-')
	{
		char tmpArr[3] = {cube[2][0][0], cube[2][0][1], cube[2][0][2]};

		cube[2][0][0] = cube[4][0][0];
		cube[2][0][1] = cube[4][0][1];
		cube[2][0][2] = cube[4][0][2];

		cube[4][0][0] = cube[3][2][2];
		cube[4][0][1] = cube[3][2][1];
		cube[4][0][2] = cube[3][2][0];

		cube[3][2][2] = cube[5][0][0];
		cube[3][2][1] = cube[5][0][1];
		cube[3][2][0] = cube[5][0][2];

		cube[5][0][0] = tmpArr[0];
		cube[5][0][1] = tmpArr[1];
		cube[5][0][2] = tmpArr[2];
	}
	if(direction == '+')
	{
		char tmpArr[3] = {cube[2][0][0], cube[2][0][1], cube[2][0][2]};

		cube[2][0][0] = cube[5][0][0];
		cube[2][0][1] = cube[5][0][1];
		cube[2][0][2] = cube[5][0][2];

		cube[5][0][0] = cube[3][2][2];
		cube[5][0][1] = cube[3][2][1];
		cube[5][0][2] = cube[3][2][0];

		cube[3][2][2] = cube[4][0][0];
		cube[3][2][1] = cube[4][0][1];
		cube[3][2][0] = cube[4][0][2];

		cube[4][0][0] = tmpArr[0];
		cube[4][0][1] = tmpArr[1];
		cube[4][0][2] = tmpArr[2];
	}

	turnSide(direction, 0);
}

void turnDown(char direction)
{
	if(direction == '-')
	{
		char tmpArr[3] = {cube[2][2][0], cube[2][2][1], cube[2][2][2]};

		cube[2][2][0] = cube[5][2][0];
		cube[2][2][1] = cube[5][2][1];
		cube[2][2][2] = cube[5][2][2];

		cube[5][2][0] = cube[3][0][2];
		cube[5][2][1] = cube[3][0][1];
		cube[5][2][2] = cube[3][0][0];

		cube[3][0][2] = cube[4][2][0];
		cube[3][0][1] = cube[4][2][1];
		cube[3][0][0] = cube[4][2][2];

		cube[4][2][0] = tmpArr[0];
		cube[4][2][1] = tmpArr[1];
		cube[4][2][2] = tmpArr[2];
	}
	if(direction == '+')
	{
		char tmpArr[3] = {cube[2][2][0], cube[2][2][1], cube[2][2][2]};

		cube[2][2][0] = cube[4][2][0];
		cube[2][2][1] = cube[4][2][1];
		cube[2][2][2] = cube[4][2][2];

		cube[4][2][0] = cube[3][0][2];
		cube[4][2][1] = cube[3][0][1];
		cube[4][2][2] = cube[3][0][0];

		cube[3][0][2] = cube[5][2][0];
		cube[3][0][1] = cube[5][2][1];
		cube[3][0][0] = cube[5][2][2];

		cube[5][2][0] = tmpArr[0];
		cube[5][2][1] = tmpArr[1];
		cube[5][2][2] = tmpArr[2];
	}

	turnSide(direction, 1);
}

void turnFront(char direction)
{
	if(direction == '-')
	{
		char tmpArr[3] = {cube[0][2][0], cube[0][2][1], cube[0][2][2]};

		cube[0][2][0] = cube[5][0][0];
		cube[0][2][1] = cube[5][1][0];
		cube[0][2][2] = cube[5][2][0];

		cube[5][0][0] = cube[1][0][2];
		cube[5][1][0] = cube[1][0][1];
		cube[5][2][0] = cube[1][0][0];

		cube[1][0][2] = cube[4][2][2];
		cube[1][0][1] = cube[4][1][2];
		cube[1][0][0] = cube[4][0][2];

		cube[4][2][2] = tmpArr[0];
		cube[4][1][2] = tmpArr[1];
		cube[4][0][2] = tmpArr[2];
	}
	if(direction == '+')
	{
		char tmpArr[3] = {cube[0][2][0], cube[0][2][1], cube[0][2][2]};

		cube[0][2][0] = cube[4][2][2];
		cube[0][2][1] = cube[4][1][2];
		cube[0][2][2] = cube[4][0][2];

		cube[4][2][2] = cube[1][0][2];
		cube[4][1][2] = cube[1][0][1];
		cube[4][0][2] = cube[1][0][0];

		cube[1][0][2] = cube[5][0][0];
		cube[1][0][1] = cube[5][1][0];
		cube[1][0][0] = cube[5][2][0];

		cube[5][0][0] = tmpArr[0];
		cube[5][1][0] = tmpArr[1];
		cube[5][2][0] = tmpArr[2];
	}

	turnSide(direction, 2);
}

void turnBack(char direction)
{
	if(direction == '-')
	{
		char tmpArr[3] = {cube[0][0][2], cube[0][0][1], cube[0][0][0]};

		cube[0][0][2] = cube[4][0][0];
		cube[0][0][1] = cube[4][1][0];
		cube[0][0][0] = cube[4][2][0];

		cube[4][0][0] = cube[1][2][0];
		cube[4][1][0] = cube[1][2][1];
		cube[4][2][0] = cube[1][2][2];

		cube[1][2][0] = cube[5][2][2];
		cube[1][2][1] = cube[5][1][2];
		cube[1][2][2] = cube[5][0][2];

		cube[5][2][2] = tmpArr[0];
		cube[5][1][2] = tmpArr[1];
		cube[5][0][2] = tmpArr[2];
	}
	if(direction == '+')
	{
		char tmpArr[3] = {cube[0][0][2], cube[0][0][1], cube[0][0][0]};

		cube[0][0][2] = cube[5][2][2];
		cube[0][0][1] = cube[5][1][2];
		cube[0][0][0] = cube[5][0][2];

		cube[5][2][2] = cube[1][2][0];
		cube[5][1][2] = cube[1][2][1];
		cube[5][0][2] = cube[1][2][2];

		cube[1][2][0] = cube[4][0][0];
		cube[1][2][1] = cube[4][1][0];
		cube[1][2][2] = cube[4][2][0];

		cube[4][0][0] = tmpArr[0];
		cube[4][1][0] = tmpArr[1];
		cube[4][2][0] = tmpArr[2];
	}

	turnSide(direction, 3);
}

void turnLeft(char direction)
{
	if(direction == '-')
	{
		char tmpArr[3] = {cube[2][0][0], cube[2][1][0], cube[2][2][0]};

		cube[2][0][0] = cube[1][0][0];
		cube[2][1][0] = cube[1][1][0];
		cube[2][2][0] = cube[1][2][0];

		cube[1][0][0] = cube[3][0][0];
		cube[1][1][0] = cube[3][1][0];
		cube[1][2][0] = cube[3][2][0];

		cube[3][0][0] = cube[0][0][0];
		cube[3][1][0] = cube[0][1][0];
		cube[3][2][0] = cube[0][2][0];

		cube[0][0][0] = tmpArr[0];
		cube[0][1][0] = tmpArr[1];
		cube[0][2][0] = tmpArr[2];
	}
	if(direction == '+')
	{
		char tmpArr[3] = {cube[2][0][0], cube[2][1][0], cube[2][2][0]};

		cube[2][0][0] = cube[0][0][0];
		cube[2][1][0] = cube[0][1][0];
		cube[2][2][0] = cube[0][2][0];

		cube[0][0][0] = cube[3][0][0];
		cube[0][1][0] = cube[3][1][0];
		cube[0][2][0] = cube[3][2][0];

		cube[3][0][0] = cube[1][0][0];
		cube[3][1][0] = cube[1][1][0];
		cube[3][2][0] = cube[1][2][0];

		cube[1][0][0] = tmpArr[0];
		cube[1][1][0] = tmpArr[1];
		cube[1][2][0] = tmpArr[2];
	}

	turnSide(direction, 4);
}

void turnRight(char direction)
{
	if(direction == '-')
	{
		char tmpArr[3] = {cube[2][2][2], cube[2][1][2], cube[2][0][2]};

		cube[2][2][2] = cube[0][2][2];
		cube[2][1][2] = cube[0][1][2];
		cube[2][0][2] = cube[0][0][2];

		cube[0][2][2] = cube[3][2][2];
		cube[0][1][2] = cube[3][1][2];
		cube[0][0][2] = cube[3][0][2];

		cube[3][2][2] = cube[1][2][2];
		cube[3][1][2] = cube[1][1][2];
		cube[3][0][2] = cube[1][0][2];

		cube[1][2][2] = tmpArr[0];
		cube[1][1][2] = tmpArr[1];
		cube[1][0][2] = tmpArr[2];
	}
	if(direction == '+')
	{
		char tmpArr[3] = {cube[2][2][2], cube[2][1][2], cube[2][0][2]};

		cube[2][2][2] = cube[1][2][2];
		cube[2][1][2] = cube[1][1][2];
		cube[2][0][2] = cube[1][0][2];

		cube[1][2][2] = cube[3][2][2];
		cube[1][1][2] = cube[3][1][2];
		cube[1][0][2] = cube[3][0][2];

		cube[3][2][2] = cube[0][2][2];
		cube[3][1][2] = cube[0][1][2];
		cube[3][0][2] = cube[0][0][2];

		cube[0][2][2] = tmpArr[0];
		cube[0][1][2] = tmpArr[1];
		cube[0][0][2] = tmpArr[2];
	}

	turnSide(direction, 5);
}

void turnSide(char direction, int sideNum)
{	if(direction == '-')
	{
		char tmp = cube[sideNum][0][0];
		cube[sideNum][0][0] = cube[sideNum][0][2];
		cube[sideNum][0][2] = cube[sideNum][2][2];
		cube[sideNum][2][2] = cube[sideNum][2][0];
		cube[sideNum][2][0] = tmp;

		tmp = cube[sideNum][0][1];
		cube[sideNum][0][1] = cube[sideNum][1][2];
		cube[sideNum][1][2] = cube[sideNum][2][1];
		cube[sideNum][2][1] = cube[sideNum][1][0];
		cube[sideNum][1][0] = tmp;
	}
	if(direction == '+')
	{
		char tmp = cube[sideNum][0][0];
		cube[sideNum][0][0] = cube[sideNum][2][0];
		cube[sideNum][2][0] = cube[sideNum][2][2];
		cube[sideNum][2][2] = cube[sideNum][0][2];
		cube[sideNum][0][2] = tmp;

		tmp = cube[sideNum][0][1];
		cube[sideNum][0][1] = cube[sideNum][1][0];
		cube[sideNum][1][0] = cube[sideNum][2][1];
		cube[sideNum][2][1] = cube[sideNum][1][2];
		cube[sideNum][1][2] = tmp;
	}
}

void printAnswer()
{
	string answer = "";

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
			answer += cube[0][i][j];
		answer += "\n";
	}

	cout << answer;
}