#include <iostream>
#include <string>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();
void maleAction(int num);
void femaleAction(int num);

bool arr[100];
int switchNum, studentNum;

int main()
{
	scanData();
	solveProblem();
	printAnswer();

	return 0;
}
void scanData()
{
	cin >> switchNum;

	for(int i = 0; i < switchNum; i++)
		cin >> arr[i];

	cin >> studentNum;
}
void solveProblem()
{
	for(int i = 0; i < studentNum; i++)
	{
		int sex, num;
		cin >> sex >> num;

		if(sex == 1)
			maleAction(num);
		else if(sex == 2)
			femaleAction(num);
	}
}
void printAnswer()
{
	string answer = to_string(arr[0]);

	for(int i = 1; i < switchNum; i++)
	{
		if(i % 20 == 0)
			answer += "\n";
		else
			answer += " ";

		answer += to_string(arr[i]);
	}

	cout << answer << endl;
}
void maleAction(int num)
{
	for(int i = num; i <= switchNum; i += num)
		arr[i - 1] = !arr[i - 1];
}
void femaleAction(int num)
{
	int minNum = num;
	int maxNum = num;

	while(true)
	{
		if(minNum == 1)
			break;
		if(maxNum == switchNum)
			break;
		if(arr[minNum-2] != arr[maxNum])
			break;

		minNum--;
		maxNum++;
	}

	for(int i = minNum; i <= maxNum; i++)
		arr[i - 1] = !arr[i-1];
}