#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

void scanData();
void solveProblem();
void bfs();
void printAnswer();

vector<pair<int, int>> lampPos;
queue<pair<int, int>> bfsQue;
int w, h, n;
int arr[52][52];
string ans;

int main()
{
    scanData();
    solveProblem();
    printAnswer();

    return 0;
}

void scanData()
{
    int x, y;
    string order;
    cin >> w >> h >> n;

    for(int i = 0; i < 52; i++)
        for(int j = 0; j < 52; j++)
            arr[i][j] = -1;

    for(int i = 0; i < n; i++)
    {
        cin >> order >> x >> y;
        x++;
        y++;

        if(order == "redstone_block"){
            arr[x][y] = 16;
            bfsQue.push(pair<int, int> {x, y});
        }
        else if(order == "redstone_dust")
            arr[x][y] = 0;
        else
            lampPos.push_back(pair<int, int> {x, y});
    }
}

void solveProblem()
{
    if(bfsQue.empty() != true)
        bfs();

    /*
    for(int i = 1; i <= w; i++)
    {
        for(int j = 1; j <= h; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    */

    ans = "success";

    for(int i = 0; i < lampPos.size(); i++)
    {
        bool trig = false;

        for(int j = 0; j < 4; j++)
        {
            int x = lampPos[i].first;
            int y = lampPos[i].second;

            if(j == 0)
                x--;
            else if(j == 1)
                x++;
            else if(j == 2)
                y--;
            else if(j == 3)
                y++;

            if(arr[x][y] > 1)
            {
                trig = true;
                break;
            }
        }

        if(trig == false)
        {
            ans = "failed";
            return;
        }
    }
}

void bfs()
{
    int x = bfsQue.front().first;
    int y = bfsQue.front().second;
    int nextPow = arr[x][y] - 1;
    bfsQue.pop();

    if(arr[x - 1][y] != -1 && arr[x - 1][y] < nextPow)
    {
        arr[x - 1][y] = nextPow;
        bfsQue.push(pair<int, int> {x - 1, y});
    }
    if(arr[x + 1][y] != -1 && arr[x + 1][y] < nextPow)
    {
        arr[x + 1][y] = nextPow;
        bfsQue.push(pair<int, int> {x + 1, y});
    }
    if(arr[x][y - 1] != -1 && arr[x][y - 1] < nextPow)
    {
        arr[x][y - 1] = nextPow;
        bfsQue.push(pair<int, int> {x, y - 1});
    }
    if(arr[x][y + 1] != -1 && arr[x][y + 1] < nextPow)
    {
        arr[x][y + 1] = nextPow;
        bfsQue.push(pair<int, int> {x, y + 1});
    }

    if(bfsQue.empty() != true)
        bfs();
}

void printAnswer()
{
    cout << ans << endl;
}