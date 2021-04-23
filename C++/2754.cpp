#include <iostream>
using namespace std;

int main(void){
	char g[2];
	float ans;

	cin >> g;
	if(g[0] == 'A')
		ans = 4;
	else if(g[0] == 'B')
		ans = 3;
	else if(g[0] == 'C')
		ans = 2;
	else if(g[0] == 'D')
		ans = 1;
	else
		ans = 0;

	if(g[1] == '+')
		ans += 0.3;
	else if(g[1] == '-')
		ans -= 0.3;

	printf("%0.1f", ans);
	return 0;
}