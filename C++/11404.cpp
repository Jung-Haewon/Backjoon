#include <iostream>
using namespace std;

void scanData();
void arrSquare();
void solveProblem();
void printAnswer();

const int INFI = 100000000;
int n, m;
int arr[100][100];
int newArr[100][100];

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
    scanf("%d", &m);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            arr[i][j] = INFI;

    for(int i = 0; i < n; i++)
        arr[i][i] = 0;

    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        if(arr[a-1][b-1] > c)
            arr[a-1][b-1] = c;
    }
}

void arrSquare()
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            newArr[i][j] = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            newArr[i][j] = arr[i][j];

            for(int x = 0; x < n; x++)
                if(arr[i][x] != INFI && arr[x][j] != INFI && newArr[i][j] > arr[i][x] + arr[x][j])
                    newArr[i][j] = arr[i][x] + arr[x][j];
        }
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            arr[i][j] = newArr[i][j];
}

void solveProblem()
{
    for(int i = 0; i < 7; i++)
        arrSquare();
}

void printAnswer()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j] != INFI)
                printf("%d", arr[i][j]);
            else
                printf("0");

            if(j != n - 1)
                printf(" ");
        }
        printf("\n");
    }
}