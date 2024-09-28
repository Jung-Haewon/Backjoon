#include <iostream>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

int n, k;
int objects[100][2];
int bestChoice[100001];

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

    for(int i = 0; i < n; i++)
        scanf("%d %d", &objects[i][0], &objects[i][1]);
}

void solveProblem()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = k; j > 0; j--)
        {
            int weight = objects[i][0];
            int value = objects[i][1];

            if(j - weight < 0)
                break;

            if(bestChoice[j - weight] + value > bestChoice[j])
                bestChoice[j] = bestChoice[j - weight] + value;
        }
    }
}

void printAnswer()
{
    cout << bestChoice[k] << endl;
}