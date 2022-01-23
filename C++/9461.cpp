#include <iostream>
using namespace std;

void dynamic(void);

long long pado[101] = {0, 1, 1, 1, 2, 2, };

int main(void)
{
	dynamic();

	int t, n;
	cin >> t;

	for(int i = 0; i < t; i++){
		scanf("%d", &n);
		cout << pado[n] << endl;
	}

	return 0;
}

void dynamic(void){
	for(int i = 6; i < 101; i++)
		pado[i] = pado[i-1] + pado[i-5];
}