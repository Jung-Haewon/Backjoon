#include <iostream>
using namespace std;

int main(void)
{

	bool ascending = true;
	bool descending = true;

	int des = 8;
	for(int i = 1; i < 9; i++)
	{
		int n;
		cin >> n;

		if(n != i)
			ascending = false;

		if(n != des)
			descending = false;

		des--;
	}

	if(ascending == true)
		printf("ascending\n");
	else if(descending == true)
		printf("descending\n");
	else
		printf("mixed\n");



	return 0;
}