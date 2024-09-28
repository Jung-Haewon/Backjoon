#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solveProblem();
void printAnswer();

string ans = "";

int main()
{
    solveProblem();
    printAnswer();

    return 0;
}

void solveProblem()
{
    while(true)
    {
        vector<int> div;
        int n;
        int sum = 0;
        scanf("%d", &n);

        if(n == -1)
            break;

        for(int i = 1; i <= n / 2; i++)
        {
            if(n % i == 0)
            {
                div.push_back(i);
                sum += i;
            }
        }

        if(sum == n)
        {
            ans += to_string(n) + " = ";

            for(int i = 0; i < div.size(); i++)
            {
                ans += to_string(div[i]);
                if(i != div.size() - 1) 
                    ans += " + ";
                else
                    ans += "\n";
            }
        }
        else
            ans += to_string(n) + " is NOT perfect.\n";
    }
}

void printAnswer()
{
    cout << ans;
}