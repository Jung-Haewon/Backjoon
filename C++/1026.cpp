#include <iostream>
#include <algorithm>
using namespace std;

void input();
void greedy();
void printAns();
bool comp(int a, int b);

int arrA[51];
int arrB[51];
int n;
int sum = 0;

int main(void)
{
	input();
	greedy();
	printAns();

	return 0;
}
void input()
{
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", &arrA[i]);

	for(int i = 0; i < n; i++)
		scanf("%d", &arrB[i]);
}
void greedy()
{
	sort(arrA, arrA + n, comp);
	sort(arrB, arrB + n);

	for(int i = 0; i < n; i++)
		sum += arrA[i] * arrB[i];
}
bool comp(int a, int b)
{
	if(a >= b)
		return true;
	else
		return false;
}
void printAns()
{
	printf("%d\n", sum);
}