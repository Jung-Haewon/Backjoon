#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string tmp;
	cin >> tmp;

	while(tmp != "0")
	{
		bool trigger = false;
		for(int i = 0; i < tmp.length(); i++)
		{
			if(tmp[i] != tmp[tmp.length()-i-1]){
				trigger = true;
				break;
			}
		}

		if(trigger == true)
			printf("no\n");
		else
			printf("yes\n");

		cin >> tmp;
	}


	return 0;
}