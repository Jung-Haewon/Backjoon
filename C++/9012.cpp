#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string tmp;
	string answer = "";
	int n, a, b;
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
	{
		bool trigger = false;
		cin >> tmp;
		a = 0;
		b = 0;

		for(int j = 0; j < tmp.size(); j++)
		{
			if(tmp[j] == '(')
				a++;
			else
				b++;

			if(b > a){
				trigger = true;
				break;
			}
		}

		if(trigger == false && b == a)
			answer += "YES\n";
		else
			answer += "NO\n";
			
	}

	cout << answer;

	return 0;
}