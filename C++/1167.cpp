#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void scanData();
void solveProblem();
void dfs(int curNode, int length);
void printAnswer();

vector<vector<pair<int, int>>> trees(100001);
bool visited[100001];
int n;
int ans = 0;
int startNode;

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

    for(int i = 0; i < n-1; i++)
    {
        int cur;
        scanf("%d", &cur);

        while(true)
        {
            int tmp1, tmp2;
            scanf("%d", &tmp1);

            if(tmp1 == -1)
                break;

            scanf("%d", &tmp2);

            trees[cur].push_back(pair<int, int> {tmp1, tmp2});
            trees[tmp1].push_back(pair<int, int> {cur, tmp2});
        }   
    }
}

void solveProblem()
{
    visited[1] = true;
    dfs(1, 0);

    for(int j = 1; j <= n; j++)
        visited[j] = false;

    visited[startNode] = true;
    dfs(startNode, 0);
}

void dfs(int curNode, int length)
{
    if(length > ans){
        ans = length;
        startNode = curNode;
    }

    for(int i = 0; i < trees[curNode].size(); i++)
    {
        int nextNode = trees[curNode][i].first;
        int nextLen = trees[curNode][i].second + length;

        if(visited[nextNode] == true)
            continue;

        visited[nextNode] = true;
        dfs(nextNode, nextLen);
    }
}

void printAnswer()
{
    printf("%d\n", ans);
}