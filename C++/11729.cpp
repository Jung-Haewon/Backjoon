#include <iostream>
#include <string>
using namespace std;

int countFunc(int a);
void recFunc(void);

string answer = "13";

int main(void){
	int n;
	int count = 1;
	cin >> n;

	for(int i = 0; i < n-1; i++){
		count = countFunc(count);
		recFunc();
	}

	cout << count << endl;
	for(int i = 0; i < answer.length(); i++){
		cout << answer[i];
		if(i%2 == 1)
			printf("\n");
		else
			printf(" ");
	}

	return 0;
}

int countFunc(int a){
	return a * 2 + 1;
}

void recFunc(void)
{
	string tmp = "";

	for(int i = 0; i < answer.length(); i++){
		if(answer[i] == '3')
			tmp += '2';
		else if(answer[i] == '2')
			tmp += '3';
		else
			tmp += '1';
	}

	tmp += "13";

	for(int i = 0; i < answer.length(); i++){
		if(answer[i] == '1')
			tmp += '2';
		else if(answer[i] == '2')
			tmp += '1';
		else
			tmp += '3';
	}

	answer = tmp;
}