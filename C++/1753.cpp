#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

void scanData();
void solveProblem();
void bfs();
void printAnswer();

int n, e, k;
vector<vector<pair<int, int>>> graph(20001);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> bfsQue;
int minLen[20001];

int main()
{
    scanData();
    solveProblem();
    printAnswer();

    return 0;
}

void scanData()
{
    scanf("%d %d", &n, &e);
    scanf("%d", &k);

    for(int i = 0; i < e; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u].push_back(pair<int, int> {v, w});
    }

    for(int i = 1; i <= n; i++)
        minLen[i] = 30000000;
}

void solveProblem()
{
    minLen[k] = 0;
    bfsQue.push(pair<int, int> {0, k});
    bfs();
}

void bfs()
{
    while(bfsQue.empty() != true)
    {
        int curNode = bfsQue.top().second;
        bfsQue.pop();

        for(int i = 0; i < graph[curNode].size(); i++)
        {
            int nextNode = graph[curNode][i].first;
            int newLen = minLen[curNode] + graph[curNode][i].second;

            if(minLen[nextNode] > newLen)
            {
                minLen[nextNode] = newLen;
                bfsQue.push(pair<int, int> {newLen, nextNode});
            }
        }
    }
}  

void printAnswer()
{
    string ans = "";

    for(int i = 1; i <= n; i++)
    {
        if(minLen[i] != 30000000)
            ans += to_string(minLen[i]) + "\n";
        else
            ans += "INF\n";
    }

    cout << ans;
}