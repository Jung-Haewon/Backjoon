#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

char arr[15]; 
int l, c;
string answer = "";

void search(string str, int cnt, int start)
{
	if(cnt == l)
	{
		int vowel = 0;
		if(str.find("a") != -1)
			vowel++;
		if(str.find("e") != -1)
			vowel++;
		if(str.find("i") != -1)
			vowel++;
		if(str.find("o") != -1)
			vowel++;
		if(str.find("u") != -1)
			vowel++;

		if(vowel < 1 || l - vowel < 2)
			return;

		answer += str + "\n";
		return;
	}
	else if(cnt < l && start > c)
		return;

	for(int i = start; i < c; i++)
		search(str + arr[i], cnt + 1, i + 1);
}

int main(void)
{
	scanf("%d %d", &l, &c);

	for(int i = 0; i < c; i++)
		cin >> arr[i];

	sort(arr, arr + c);

	search("", 0, 0);

	cout << answer;

	return 0;
}