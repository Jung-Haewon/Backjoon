#include <iostream>
#include <string>
using namespace std;

void dynamicProgramming();
string stringAdd(string a, string b);
void scanData();
void printAnswer();

string comb[101][101];
long long n, m;

int main()
{
	dynamicProgramming();

	scanData();
	printAnswer();

	return 0;
}

void dynamicProgramming()
{
	for(int i = 1; i < 101; i++)
	{
		comb[i][0] = "1";
		comb[i][i] = "1";
	}

	for(int i = 2; i < 101; i++){
		for(int j = 1; j < i; j++){
			comb[i][j] = stringAdd(comb[i-1][j], comb[i-1][j-1]);

			cout << i << " Comb " << j << ": " << comb[i][j] << endl;
		}
	}
}

string stringAdd(string a, string b)
{
	if(a.length() < b.length())
	{
		string c = a;
		a = b;
		b = c;
	}

	bool isCarry = false;
	string ret = "";

	for(int i = 1; i <= a.length(); i++)
	{
		//cout << int(a[a.length() - i]) - 48 << " " << int(b[b.length() - i]) - 48 << endl;

		int tmp = 0;
		tmp += int(a[a.length() - i]) - 48;

		if(b.length() >= i)
			tmp += int(b[b.length() - i]) - 48;

		if(isCarry == true)
		{
			tmp += 1;
			isCarry = false;
		}

		if(tmp >= 10)
			isCarry = true;

		ret = to_string(tmp % 10) + ret;
	}

	if(isCarry == true)
		ret = "1" + ret;

	return ret;
}

void scanData()
{
	cin >> n >> m;
}

void printAnswer()
{
	cout << comb[n][m] << endl;
}