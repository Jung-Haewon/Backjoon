#include <iostream>
#include <queue>
using namespace std;

void scanData();
void solveProblem();
void bfs();
void printAnswer();

queue<pair<int, int>> bfsQue;
int minTime[100001];
bool visited[100001];
int n, k;

int main()
{
    scanData();
    solveProblem();
    printAnswer();

    return 0;
}

void scanData()
{
    scanf("%d %d", &n, &k);
}

void solveProblem()
{
    visited[n] = true;
    bfsQue.push(pair<int, int> {n, 0});
    bfs();
}

void bfs()
{
    int curX = bfsQue.front().first;
    int curTime = bfsQue.front().second;
    bfsQue.pop();

    if(curX < k)
    {
        if((visited[curX + 1] == false) || (minTime[curX + 1] > curTime + 1))
        {
            visited[curX + 1] = true;
            minTime[curX + 1] = curTime + 1;
            bfsQue.push(pair<int, int> {curX + 1, curTime + 1});
        }
    }

    if(curX > 0)
    {
        if((visited[curX - 1] == false) || (minTime[curX - 1] > curTime + 1))
        {
            visited[curX - 1] = true;
            minTime[curX - 1] = curTime + 1;
            bfsQue.push(pair<int, int> {curX - 1, curTime + 1});
        }
    }
    
    if((curX != 0) && (curX < k) && (curX <= 50000))
    {
        if((visited[curX * 2] == false) || (minTime[curX * 2] > curTime))
        {
            visited[curX * 2] = true;
            minTime[curX * 2] = curTime;
            bfsQue.push(pair<int, int> {curX * 2, curTime});
        }
    }

    if(bfsQue.empty() != true)
        bfs();
}

void printAnswer()
{
    cout << minTime[k] << endl;
}