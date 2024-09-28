#include <iostream>
using namespace std;

void solveProblem();
void printAnswer();

int arr[18];
int n;

int main()
{
    solveProblem();
    printAnswer();

    return 0;
}

void solveProblem()
{
    arr[10] = 6;

    for(int i = 11; i < 18; i++)
        arr[i] = arr[i-1] * i;

    cin >> n;
}

void printAnswer()
{
    cout << arr[n] << endl;
}