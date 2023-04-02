#include <iostream>
#include <set>
#include <string>
using namespace std;

struct Compare {
	bool operator() (const int a, const int b) const{
		if(abs(a) != abs(b))
			return abs(a) < abs(b);
		return a < b;
	}
};

void scanData();
void solveProblem();
void popAction();
void insertAction(int a);
void printAnswer();

multiset<int, Compare> arr;
int n;
string answer = "";

int main()
{
	scanData();
	solveProblem();
	printAnswer();

	return 0;
}

void scanData()
{
	scanf("%d", &n);
}

void solveProblem()
{
	int x;

	for(int i = 0; i < n; i++)
	{
		scanf("%d", &x);

		if(x == 0)
			popAction();
		else
			insertAction(x);
	}
}

void popAction()
{
	if(arr.empty() == true)
	{
		answer += "0\n";
		return;
	}

	answer += to_string(*arr.begin()) + "\n";
	arr.erase(arr.begin());
}

void insertAction(int a)
{
	arr.insert(a);
}

void printAnswer()
{
	cout << answer;
}