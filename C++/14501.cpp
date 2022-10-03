#include <iostream>
using namespace std;

void scanData();
void printAnswer();
void bruteForce(int day, int earn);

int n;
int arr[16][2];
int ans = 0;

int main(void)
{
	scanData();
	bruteForce(1, 0);
	printAnswer();
}
void bruteForce(int day, int earn)
{
	//0. 현재까지 들어온 수입의 총합이, 기존 최대값보다 큰 경우 정답 교체.
	if(earn > ans)
		ans = earn;

	if(day > n)
		return;

	//1. 당일 상담을 선택한 경우.
	//당일 상담을 선택해도 퇴사 이전에 끝나는 경우에만 선택한다.
	if(n + 1 >= day + arr[day][0])
		bruteForce(day + arr[day][0], earn + arr[day][1]);

	//2. 당일 상담을 선택하지 않고, 다음날로 넘어가는 경우.
	//내일이 퇴사하는 날인 경우는 제외한다.
	if(n >= day + 1)
		bruteForce(day + 1, earn);
}
void scanData()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d %d", &arr[i][0], &arr[i][1]);
}
void printAnswer()
{
	printf("%d", ans);
}