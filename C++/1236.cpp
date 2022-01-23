#include <iostream>
using namespace std;

int max(int n1, int n2);
char arr[50][50];

int main(void)
{
	int n, m;
	cin >> n >> m;

	int remainN = n;
	int remainM = m;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> arr[i][j];

	for(int i = 0; i < n; i++){
		bool trigger = false;

		for(int j = 0; j < m; j++){
			if(arr[i][j] == 'X'){
				trigger = true;
				break;
			}
		}

		if(trigger == true)
			remainN--;
	}

	for(int i = 0; i < m; i++){
		bool trigger = false;

		for(int j = 0; j < n; j++){
			if(arr[j][i] == 'X'){
				trigger = true;
				break;
			}
		}

		if(trigger == true)
			remainM--;
	}

	cout << max(remainN, remainM) << endl;

	return 0;
}

int max(int n1, int n2)
{
	if(n1 > n2)
		return n1;
	else
		return n2;
}