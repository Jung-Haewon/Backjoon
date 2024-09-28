#include <iostream>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

int n, m;
int arr[1000][2];

int main()
{
    scanData();
    solveProblem();
    printAnswer();

    return 0;
}

void scanData()
{
    for(int i = 0; i < 1000; i++)
    {
        arr[i][0] = -1;
        arr[i][1] = -1;
    }

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int a, c;
        char b;

        cin >> a >> b >> c;
        a--;

        if(b == 'P')
            arr[a][0] = c;
        else
            arr[a][1] = c;
    }
}

void solveProblem()
{
    int worst = 0;
    int best = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i][0] == 1 && arr[i][1] == 0)
            worst++;
        if(arr[i][0] != 0 && arr[i][1] != 1)
            best++;
    }

    cout << worst << " " << best << "\n";
}

void printAnswer()
{
    
}