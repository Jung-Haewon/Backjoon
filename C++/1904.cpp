#include <iostream>
using namespace std;

int n;
int ans = 0;

void dp(int cur){
	if(n - cur <= 1)
		ans++;
	else{
		dp(cur + 1);
		dp(cur + 2);
	}
}

int main(void){
	scanf("%d", &n);
	dp(0);
	printf("%d", ans);

	return 0;
}