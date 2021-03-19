#include <iostream>
#include <string>
using namespace std;

bool hansu(int n)
{
	string number = to_string(n);
	bool ans = true;
	int tmp = (int)number[0] - (int)number[1]; 

	for(int i = 0; i < number.length()-1; i++)
	{
		if(tmp != number[i] - number[i+1])
			ans = false;
	}
	return ans;
}


int main(void)
{
	int n, cnt = 0;
	cin >> n;

	while(n != 0)
	{
		if(hansu(n) == true)
			cnt++;
		n--;
	}

	cout << cnt << endl;

	return 0;
}