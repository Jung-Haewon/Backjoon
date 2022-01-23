#include <iostream>
using namespace std;

int Abs(int n);

int main(void)
{
	int a, b, c, d, ans1, ans2;
	scanf("%d %d", &a, &b);

	if(a == 0){
		printf("0\n0");
		return 0;
	}

	c = Abs(a);
	d = Abs(b);

	ans1 = c / d;
	ans2 = c % d;

	if(a > 0 && b > 0)
		printf("%d\n%d", ans1, ans2);
	else if(a > 0 && b < 0)
		printf("%d\n%d", -ans1, ans2);
	else if(a < 0 && b > 0){
		if(ans2 > 0){
			ans1++;
			ans2 = -ans2 + d;
		}
		printf("%d\n%d", -ans1, ans2);
	}
	else{
		if(ans2 > 0){
			ans1++;
			ans2 = -ans2 + d;
		}
		printf("%d\n%d", ans1, ans2);
	}
}

int Abs(int n)
{
	if(n < 0)
		return -n;
	else
		return n;
}