#include <iostream>
#include <queue>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();
int calDistance(int start, int end);

struct Town
{
    int dist;
    int townNum;
};

struct cmp
{
    bool operator()(Town a, Town b)
    {
        return a.dist > b.dist;
    }
};

vector<vector<pair<int, int>>> loads(1001);
int N, M, X;
int ans = 0;

int main(void)
{
    scanData();
    solveProblem();
    printAnswer();

    return 0;
}

void scanData()
{
    scanf("%d %d %d", &N, &M, &X);

    for(int i = 0 ; i < M; i++)
    {
        int start, end, time;
        scanf("%d %d %d", &start, &end, &time);

        loads[start].push_back(pair<int, int> {end, time});
    }

    for(int i = 1; i <= N; i++)
        loads[i].push_back(pair<int, int> {i, 0});

    // for(int i = 1; i <= N; i++)
    // {
    //  cout << i << endl;
    //  for(int j = 0; j < loads[i].size(); j++)
    //  {
    //      cout << loads[i][j].first << " " << loads[i][j].second << endl;
    //  }
    //  cout << endl;
    // }
}

void solveProblem()
{
    for(int i = 1; i <= N; i++)
    {
        int townToParty = calDistance(i, X);
        int partyToTown = calDistance(X, i);
        int dist = townToParty + partyToTown;

        //cout << i << " " << townToParty << " " << partyToTown << endl;

        if(dist > ans)
            ans = dist;
    }
}

int calDistance(int start, int end)
{
    int distance[1001];
    for(int i = 0; i < 1001; i++)
        distance[i] = -1;

    priority_queue<Town, vector<Town>, cmp> nextTowns;
    nextTowns.push(Town{0, start});

    while(nextTowns.empty() == false)
    {
        Town curTown = nextTowns.top();
        int curDist = curTown.dist;
        int curNum = curTown.townNum;
        nextTowns.pop();

        if(distance[curNum] != -1 && distance[curNum] < curDist)
            continue;

        for(int i = 0; i < loads[curNum].size(); i++)
        {
            int nextNum = loads[curNum][i].first;
            int nextDist = curDist + loads[curNum][i].second;
            
            if(nextDist < distance[nextNum] || distance[nextNum] == -1)
            {
                nextTowns.push(Town{nextDist, nextNum});
                distance[nextNum] = nextDist;
            }
        }
    }

    return distance[end];
}

void printAnswer()
{
    cout << ans << endl;
}