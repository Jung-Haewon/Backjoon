#include <iostream>
using namespace std;

int main(void)
{
	int answer = 0;
	int tmp;

	for(int i = 0; i < 6; i++){
		cin >> tmp;
		answer += tmp * 5;
	}

	cout << answer;
}