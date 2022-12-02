#include <iostream>
#include <vector>
using namespace std;

void initData();
void printAnswer();
void showSatellite();

void solveProblem();
int calMoveLength(int n);

vector<int> satellite;

int main()
{
	initData();
	solveProblem();
	printAnswer();

	return 0;
}

void initData()
{
	int startNum, endNum;
	cin >> startNum >> endNum;

	for(int i = startNum; i <= endNum; i++)
		satellite.push_back(i);
}

void printAnswer()
{
	cout << satellite[0] << endl;
}

void showSatellite()
{	//올바로 실행되는지 점검용 함수
	for(int i = 0; i < satellite.size(); i++)
		cout << satellite[i] << endl;
	cout << endl;
}

void solveProblem()
{
	vector<int>::iterator curIter = satellite.begin();
	int moveLen;

	while(true)
	{
		if(satellite.size() == 1)
			break;

		//cout << "curIter: " << *curIter << endl;
		//showSatellite();

		moveLen = calMoveLength(*curIter);
		satellite.erase(curIter);

		if(curIter == satellite.end())
			curIter = satellite.begin();

		for(int i = 1; i < moveLen; i++)
		{
			curIter += 1;

			if(curIter == satellite.end())
				curIter = satellite.begin();
		}
	}
}

int calMoveLength(int n)
{
	return (n % 3) + 2;
}