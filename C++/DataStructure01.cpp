#include <iostream>
using namespace std;

void Dynamic();

int arr[2001][2];

int main()
{
	Dynamic();

	int x, y;
	while(cin >> x >> y)
	{
		if(arr[x][0] < y)
			printf("out\n");
		else if(arr[x][1] > y)
			printf("in\n");
		else
			printf("on\n");
	}
}

void Dynamic()
{
	int tmp = 0;
	int xPos = 0;
	int yPos = 0;
	int n = 1;
	
	for(int i = 0; i <= 2000; i++)
	{
		arr[i][0] = 0;
		arr[i][1] = 0;
	}

	scanf("%d", &tmp);

	while(tmp != 0)
	{
		if(n % 2 == 1)
		{
			arr[xPos][1] = yPos;
			arr[xPos + tmp][0] = yPos;

			for(int i = xPos + 1; i < xPos + tmp; i++)
			{
				arr[i][0] = yPos;
				arr[i][1] = yPos;
			}

			xPos = xPos + tmp;
		}
		else
		{
			yPos = yPos - tmp;
		}

		scanf("%d", &tmp);
		n = n + 1;
	}

	for(int i = 0; i <= xPos; i++)
	{
		arr[i][0] = arr[i][0] - yPos;
		arr[i][1] = arr[i][1] - yPos;
	}

	arr[xPos][1] = 0;
}