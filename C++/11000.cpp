#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void scanData();
void countRoom();
void printAnswer();
//void showLectures();
bool compare(pair<int, int> a, pair<int, int> b);

vector<pair<int, int>> lectures;
int room = 0;

int main(void)
{
	scanData();
	countRoom();
	printAnswer();

	return 0;
}

void scanData()
{
	int n, sTmp, tTmp;
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
	{
		scanf("%d %d", &sTmp, &tTmp);
		lectures.push_back(make_pair(sTmp, tTmp));
	}

	sort(lectures.begin(), lectures.end(), compare);
}

void countRoom()
{
	vector<pair<int, int>>::iterator iter;

	while(true)
	{
		//showLectures();
		room++;
		int cur = 0;
		for(iter = lectures.begin(); iter != lectures.end(); iter++)
		{
			if(lectures[lectures.size()-1].first < cur)
				break;

			if((*iter).first < cur)
				continue;

			cur = (*iter).second;
			lectures.erase(iter);
			iter--;
		}

		if(lectures.size() == 0)
			break;
	}
}


void printAnswer()
{
	cout << room << endl;
}

bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}

/*
void showLectures()
{
	vector<pair<int, int>>::iterator iter;

	for(iter = lectures.begin(); iter != lectures.end(); iter++)
		cout << (*iter).first << " " << (*iter).second << endl;
	cout << endl << endl;
}
*/