#include <iostream>
#include <string>
using namespace std;

string rev(string str);

int main(void)
{
	string x, y;
	cin >> x >> y;

	cout << stoi(rev(to_string(stoi(rev(x)) + stoi(rev(y))))) << endl;

	return 0;
}

string rev(string str)
{
	string tmp;
	for(int i = str.length() - 1; i >= 0; i--)
		tmp += str[i];

	return tmp;
}