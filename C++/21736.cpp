#include <iostream>
using namespace std;

void scanData();
void solveProblem();
void dfs(int x, int y);
void printAnswer();

char graph[602][602];
bool visited[602][602];
int n, m;
int curX, curY;
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
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> graph[i][j];

            if(graph[i][j] == 'I')
            {
                curX = i;
                curY = j;
            }
        }
    }

    /*
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << graph[i][j];
        cout << endl;
    }
    */
}

void solveProblem()
{
    dfs(curX, curY);
}

void dfs(int x, int y)
{
    if(graph[x][y] == 'P')
        ans++;
    visited[x][y] = true;

    if((graph[x + 1][y] == 'O' || graph[x + 1][y] == 'P') && visited[x + 1][y] != true)
        dfs(x + 1, y);
    if((graph[x - 1][y] == 'O' || graph[x - 1][y] == 'P') && visited[x - 1][y] != true)
        dfs(x - 1, y);
    if((graph[x][y + 1] == 'O' || graph[x][y + 1] == 'P') && visited[x][y + 1] != true)
        dfs(x, y + 1);
    if((graph[x][y - 1] == 'O' || graph[x][y - 1] == 'P') && visited[x][y - 1] != true)
        dfs(x, y - 1);
}

void printAnswer()
{
    if(ans == 0)
        cout << "TT" << endl;
    else
        cout << ans << endl;
}