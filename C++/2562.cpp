#include <iostream>
using namespace std;

int main(void)
{
	int max = 0, cnt = 0, tmp;

	for(int i = 1; i < 10; i++)
	{
		cin >> tmp;
		if(tmp > max) 
			{
				max = tmp;
				cnt = i;
			}
	}

	cout << max << '\n' << cnt << endl;
	
	return 0;
}