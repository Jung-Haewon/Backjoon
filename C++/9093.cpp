#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int t;
	string testCase, tmp;

	cin >> t;
	getline(cin, testCase);

	for(int i = 0; i < t; i++)
	{
		string answer = "";
		tmp = "";
		testCase = "";
		getline(cin, testCase);

		for(int i = 0; i < testCase.length(); i++)
		{
			if(testCase[i] == ' ')
			{
				for(int j = tmp.length() - 1; j >= 0; j--)
					answer += tmp[j];
				answer += " ";
				tmp = "";
			}
			else if(testCase.length() == i + 1)
			{
				tmp += testCase[i];
				for(int j = tmp.length() - 1; j >= 0; j--)
					answer += tmp[j];
			}
			else
				tmp += testCase[i];
		}

		cout << answer << endl;
	}



	return 0;
}