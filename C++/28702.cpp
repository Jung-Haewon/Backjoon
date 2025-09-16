#include <iostream>
#include <string>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

string arr[3];
string ans = "";

int main(void)
{
	scanData();
	solveProblem();
	printAnswer();

	return 0;
}

void scanData()
{
	for(int i = 0; i < 3; i++)
		cin >> arr[i];
}

void solveProblem()
{
	int ansNum;

	for(int i = 0; i < 3; i++)
	{
		int tmp;

		if(arr[i][0] != 'F' && arr[i][0] != 'B')
		{
			tmp = stoi(arr[i]);
			ansNum = tmp + 3 - i;
			break;
		}
	}

	if(ansNum % 3 == 0 && ansNum % 5 == 0)
		ans = "FizzBuzz";
	else if(ansNum % 3 == 0)
		ans = "Fizz";
	else if(ansNum % 5 == 0)
		ans = "Buzz";
	else
		ans = to_string(ansNum);
}

void printAnswer()
{
	cout << ans << endl;
}