#include <iostream>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

int n;
int m;
int arr[10000]; 
int answer = 0;

int main()
{
    scanData();
    solveProblem();
    printAnswer();
}

void scanData()
{
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void solveProblem()
{
    for(int i = 0; i < n; i++)
    {
        int sum = 0;

        for(int j = i; j < n; j++)
        {
            sum += arr[j];

            if(sum == m)
                answer++;
        }
    }
}

void printAnswer()
{
    cout << answer << endl;
}