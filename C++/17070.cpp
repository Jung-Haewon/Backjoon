#include <iostream>
#include <string>
#include <queue>;
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

queue
int arr[18][18];
int n;

int main(void)
{
	scanData();
	solveProblem();
	printAnswer();

	return 0;
}

void scanData()
{
	for(int i = 0; i < 18; i ++)
		for(int j = 0; j < 18; j++)
			arr[i][j] = 1;

	scanf("%d", &n);
	
	for(int i = 1; i < n + 1; i++)
		for(int j = 1; j < n + 1; j++)
			scanf("%d", &arr[i][j]);

	arr[1][1] = 2;
	arr[1][2] = 2;
}

void solveProblem()
{

}

void printAnswer()
{
	for(int i = 1; i < n + 1; i++){
		for(int j = 1; j < n + 1; j++)
			cout << arr[i][j];
		cout << endl;
	}
}