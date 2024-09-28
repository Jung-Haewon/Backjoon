#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void scanData();
void solveProblem();
void dfs(string cur);
void printAnswer();

string s, t;
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
    cin >> s >> t;
}

void solveProblem()
{
    dfs(t);
}

void dfs(string cur)
{
    if(cur.length() == s.length())
    {
        if(cur == s)
            ans = 1;
        return;
    }

    if(cur[cur.length()-1] == 'A')
    {
        cur = cur.substr(0, cur.length() - 1);
        dfs(cur);
    }
    else
    {
        cur = cur.substr(0, cur.length() - 1);
        reverse(cur.begin(), cur.end());
        dfs(cur);
    }
}

void printAnswer()
{
    cout << ans << endl;
}