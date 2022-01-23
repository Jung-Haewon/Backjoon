#include <iostream>
using namespace std;

int max(int n, int m);

int curArr[500] = {0, };
int newArr[500];

int main(void)
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < i; j++){
			int tmp1, tmp2, tmp3;
			cin >> tmp1;

			if(j != 0)
				tmp2 = curArr[j - 1] + tmp1;
			else
				tmp2 = 0;
			tmp3 = curArr[j] + tmp1;
			newArr[j] = max(tmp2, tmp3);
		}
		for(int j = 0; j < i; j++)
			curArr[j] = newArr[j];
	}

	int answer = 0;
	for(int i = 0; i < n; i++){
		if(curArr[i] > answer)
			answer = curArr[i];
	}

	cout << answer << endl;

	return 0;
}

int max(int n, int m)
{
	if(n > m)
		return n;
	else
		return m;
}