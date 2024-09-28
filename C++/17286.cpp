#include <iostream>
#include <cmath>
using namespace std;

void scanData();
void solveProblem();
float distance(float x1, float y1, float x2, float y2);
void printAnswer();

float yumi[2];
float peoples[3][2];
float ans;

int main()
{
    scanData();
    solveProblem();
    printAnswer();

    return 0;
}

void scanData()
{
    cin >> yumi[0] >> yumi[1];

    for(int i = 0; i < 3; i++)
        cin >> peoples[i][0] >> peoples[i][1];
}

void solveProblem()
{
    float len[6];

    len[0] = distance(yumi[0], yumi[1], peoples[0][0], peoples[0][1])
            + distance(peoples[0][0], peoples[0][1], peoples[1][0], peoples[1][1])
            + distance(peoples[1][0], peoples[1][1], peoples[2][0], peoples[2][1]);

    len[1] = distance(yumi[0], yumi[1], peoples[0][0], peoples[0][1])
            + distance(peoples[0][0], peoples[0][1], peoples[2][0], peoples[2][1])
            + distance(peoples[2][0], peoples[2][1], peoples[1][0], peoples[1][1]);

    len[2] = distance(yumi[0], yumi[1], peoples[1][0], peoples[1][1])
            + distance(peoples[1][0], peoples[1][1], peoples[0][0], peoples[0][1])
            + distance(peoples[0][0], peoples[0][1], peoples[2][0], peoples[2][1]);

    len[3] = distance(yumi[0], yumi[1], peoples[1][0], peoples[1][1])
            + distance(peoples[1][0], peoples[1][1], peoples[2][0], peoples[2][1])
            + distance(peoples[2][0], peoples[2][1], peoples[0][0], peoples[0][1]);

    len[4] = distance(yumi[0], yumi[1], peoples[2][0], peoples[2][1])
            + distance(peoples[2][0], peoples[2][1], peoples[1][0], peoples[1][1])
            + distance(peoples[1][0], peoples[1][1], peoples[0][0], peoples[0][1]);

    len[5] = distance(yumi[0], yumi[1], peoples[2][0], peoples[2][1])
            + distance(peoples[2][0], peoples[2][1], peoples[0][0], peoples[0][1])
            + distance(peoples[0][0], peoples[0][1], peoples[1][0], peoples[1][1]);

    ans = len[0];

    for(int i = 0; i < 6; i++){
        //cout << len[i] << endl;
        if(len[i] < ans){
            ans = len[i];
        }
    }
}

float distance(float x1, float y1, float x2, float y2)
{
    float ret = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    return ret;
}

void printAnswer()
{
    printf("%.0f", floor(ans));
}