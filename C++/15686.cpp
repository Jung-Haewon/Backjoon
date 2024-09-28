#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int x, y;
    int dist[100];
};

void scanData();
void solveProblem();
void dfs(int level, int cnt, vector<int> state);
void printAnswer();

vector<Node> houses;
vector<Node> shops;
int n, m, tmp;
int ans = -1;

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

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &tmp);

            if(tmp == 1)
            {
                Node house {i, j};
                houses.push_back(house);
            }
            else if(tmp == 2)
            {
                Node shop {i, j};
                shops.push_back(shop);
            }
        }
    }

    /*
    for(auto i : houses)
        cout << i.x << " " << i.y << endl;

    cout << endl;

    for(auto i : shops)
        cout << i.x << " " << i.y << endl;
    */
}

void solveProblem()
{
    for(int i = 0; i < shops.size(); i++)
        for(int j = 0; j < houses.size(); j++)
            shops[i].dist[j] = abs(shops[i].x - houses[j].x) + abs(shops[i].y - houses[j].y);

    vector<int> arr;
    for(int i = 0; i < houses.size(); i++)
        arr.push_back(1000);

    dfs(0, 0, arr);
}

void dfs(int level, int cnt, vector<int> state)
{
    

    int cur = 0;
    for(auto i: state)
        cur += i;

    if(ans == -1)
        ans = cur;
    else if(ans > cur)
        ans = cur;

    //cout << level << " " << cnt << " " << cur << endl;

    if(level == shops.size() || cnt == m)
    {
        return;
    }

    dfs(level + 1, cnt, state);

    for(int i = 0; i < houses.size(); i++)
    {
        if(state[i] > shops[level].dist[i])
            state[i] = shops[level].dist[i];
    }

    dfs(level + 1, cnt + 1, state);
}

void printAnswer()
{
    cout << ans << endl;
}