#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void scanMap();
void scanInput();
void solveProblem();
void printAnswer();
void deleteDynamicArr();

//void printMap();
//void printInput();
//void printArea();

string answer;
char** mapArr;
char** patternArr;
int n, m;

int main(void)
{
	scanMap();
	//printMap();
	scanInput();
	//printInput();
	//printArea();

	solveProblem();
	printAnswer();
	deleteDynamicArr();

	return 0;
}

void scanMap()
{
	ifstream mapFile;
	mapFile.open("map.txt");

	if(mapFile.is_open())
	{
		mapFile >> n;
		mapArr = new char*[n];
		for(int i = 0; i < n; i++)
			mapArr[i] = new char[n];

		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				mapFile >> mapArr[i][j];
	}

	mapFile.close();
}

void scanInput()
{
	cin >> m;

	patternArr = new char*[m];
	for(int i = 0; i < m; i++)
		patternArr[i] = new char[m];

	for(int i = 0; i < m; i++)
		for(int j = 0; j < m; j++)
			cin >> patternArr[i][j];
}

void solveProblem()
{
	for(volatile int i = 0; i <= n-m; i++)
	{
		for(volatile int j = 0; j <= n-m; j++)
		{
			// i, j를 기준으로 i+m, j+m 까지와 비교
			bool ansTrigger = true;

			for(volatile int k = 0; k < m; k++)
			{
				for(volatile int l = 0; l < m; l++)
				{
					if(mapArr[i+k][j+l] != patternArr[k][l])
					{
						ansTrigger = false;
						//cout << "sibal" << endl;
						break;
					}
				}
				if(ansTrigger == false)
					break;
			}

			if(ansTrigger == false)
				continue;

			answer += to_string(j+1) + " " + to_string(i+1)+ "\n";
		}
	}
}

void printAnswer()
{
	if(answer.length() == 0)
		cout << "0 0" << endl;
	else
		cout << answer;
}

void deleteDynamicArr()
{
	for(int i = 0; i < n; i++)
		delete[] mapArr[i];
	delete[] mapArr;

	for(int i = 0; i < m; i++)
		delete[] patternArr[i];
	delete[] patternArr;
}
/*
void printMap()//디버깅용 함수
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout << mapArr[i][j] << " ";
		cout << endl;
	}
}

void printInput()//디버깅용 함수
{
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < m; j++)
			cout << patternArr[i][j] << " ";
		cout << endl;
	}
}

void printArea()
{
	for(int i = 700; i < 740; i++)
	{
		for(int j = 700; j < 740; j++)
			cout << mapArr[i][j];
		cout << endl;
	}
}
*/