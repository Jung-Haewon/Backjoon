#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	stack<int> stk;
	int k, tmp;
	int ans = 0;

	scanf("%d", &k);

	for(int i = 0; i < k; i++){
		scanf("%d", &tmp);

		if(tmp != 0){
			ans += tmp;
			stk.push(tmp);
		}
		else{
			ans -= stk.top();
			stk.pop();
		}
	}

	cout << ans << endl;


	return 0;
}