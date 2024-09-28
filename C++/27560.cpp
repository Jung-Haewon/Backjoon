#include <iostream>
#include <string>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

string ans = "";
int n;
int arr[100000];

int main()
{
    scanData();
    solveProblem();
    printAnswer();

    return 0;
}

void scanData()
{
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void solveProblem()
{
    for(int i = 0; i < n; i++)
        ans += "R";
    
    for(int i = n - 1; i >= 0; i--)
    {
        
    }
}

void printAnswer()
{
    cout << ans << endl;
}