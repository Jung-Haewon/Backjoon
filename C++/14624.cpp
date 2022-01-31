#include <iostream>
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	if(n % 2 == 1){
		for(int i = 0; i < n; i++)
			printf("*");
		printf("\n");

		for(int i = 0; i < (n + 1) / 2; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if((n / 2) - i == j || (n / 2) + i == j)
					printf("*");
				else
					printf(" ");

				if((n / 2) + i <= j)
					break;
			}
			printf("\n");
		}
	}
	else
		cout << "I LOVE CBNU" << endl;
}