#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


void inputFunc();
void SolutionFunc();
int rounding(int num);
int searchFunc(int num);

int A[100000] = {0, };
int n, m;
string answer = "";

int main(void)
{
	inputFunc();

	SolutionFunc();

	cout << answer;
	return 0;
}

void inputFunc()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	sort(A, A + n);

	cin >> m;
}

void SolutionFunc()
{
	for(int i = 0; i < m; i++)
	{
		int tmp;
		scanf("%d", &tmp);

		answer += to_string(searchFunc(tmp)) + "\n";
	}
}

int searchFunc(int num)
{
	int pos = 0;
	int len = rounding(n);

	while(true)
	{
		if(len > 1)
		{
			if(num < A[pos + len]){
				len = rounding(len);
			}
			else if(num == A[pos + len])
				return 1;
			else
			{
				pos += len;
				len = rounding(len);
				if(pos + len >= n)
					len--;
			}
		}
		else{
			if(A[pos] == num)
				return 1;
			else if(A[pos + 1] == num)
				return 1;
			else if(A[pos + 2] == num)
				return 1;
			else if(A[pos + 3] == num)
				return 1;
			else
				return 0;
		}
	}
}

int rounding(int num)
{
	if(num % 2 == 0)
		return num / 2;
	else
		return (num / 2) + 1;
}