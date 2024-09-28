#include <iostream>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();
void printStart();

char start[50][50];
char goal[50][50];
int n, m;
int ans = 0;

int main()
{
    scanData();
    solveProblem();
    printAnswer();

    return 0;
}

void scanData()
{
    char tmp;
    scanf("%d %d", &n, &m);
    scanf("%c", &tmp);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%c", &start[i][j]);
        }
        scanf("%c", &tmp);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%c", &goal[i][j]);
        }
        scanf("%c", &tmp);
    }
}

void solveProblem()
{
    for(int i = 0; i < n - 2; i++)
    {
        for(int j = 0; j < m - 2; j++)
        {
            if(start[i][j] == goal[i][j])
                continue;

            for(int x = i; x < i + 3; x++)
            {
                for(int y = j; y < j + 3; y++)
                {
                    if(start[x][y] == '1')
                        start[x][y] = '0';
                    else
                        start[x][y] = '1';
                }
            }

            ans += 1;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(start[i][j] != goal[i][j])
            {
                ans = -1;
                return;
            }
        }
    }
}

void printAnswer()
{
    cout << ans << endl;
}

void printStart()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout << start[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}