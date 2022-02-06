#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Account{
public:
	string name;
	int year;
	int cnt;

	void setAcc(string name, int year, int cnt){
		this -> name = name;
		this -> year = year;
		this -> cnt = cnt;
	}

	bool operator <(Account &acc){
		if(this -> year < acc.year)
			return true;
		else if(this -> year == acc.year && this -> cnt < acc.cnt)
			return true;
		else
			return false;
	}
};

int main(void)
{
	string tmp;
	string answer = "";
	int n, year;

	scanf("%d", &n);
	Account* accArr = new Account[n];


	for(int i = 0; i < n; i++){
		scanf("%d", &year);
		cin >> tmp;
		accArr[i].setAcc(tmp, year, i);
	}


	sort(accArr, accArr + n);



	for(int i = 0; i < n; i++)
		answer += to_string(accArr[i].year) + " " + accArr[i].name + "\n";
	

	cout << answer;


	delete[] accArr;

	
	return 0;
}