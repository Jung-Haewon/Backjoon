#include <iostream>
using namespace std;

int mod(char *S, int p);

int main(void)
{
	char* P;
	long long k, r;
	int i = 2;
	cin >> P >> k;

	while(true){
		if(mod(P, i) == 0){
			r = i;
			break;
		}
		i++;
	}
	if(r < k)
		cout << "BAD" << " " << r;
	else
		cout << "GOOD";

	return 0;
}

int mod(char *S, int p)
{
	// S는 수를 문자열로 표현한 것, 1324 -> "1324"
	int ret = 0;
	for (int i=0;S[i];i++) ret = (ret*10 + (S[i]-'0')) % p;
	return ret;
}