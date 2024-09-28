#include <iostream>
#include <string>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

string str = "";
int cnt = 0;

int main()
{
    scanData();
    solveProblem();
    printAnswer();

    return 0;
}

void scanData()
{
    cin >> str;
}

void solveProblem()
{
    bool trigger = false;
    char first = str[0];

    for(char c : str)
    {
        if(c == first){
            if(trigger == true)
                trigger = false;
        }
        else
        {
            if(trigger == false)
            {
                trigger = true;
                cnt++;
            }
        }
    }
}

void printAnswer()
{
    cout << cnt << endl;
}