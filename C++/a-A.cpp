#include <iostream>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

int arr[1001];
int n, q;

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

    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &q);
}

void solveProblem()
{
    for(int i = 0; i < q; i++)
    {
        int qur, l, r, k;
        scanf("%d %d %d", &qur, &l, &r);

        if(qur == 1)
        {
            scanf("%d", &k);

            int ret = 0;
            for(int j = l; j <= r; j++)
                if(arr[j] == k)
                    ret++;

            printf("%d\n", ret);
        }
        else if(qur == 2)
        {
            for(int j = l; j <= r; j++)
                arr[j] = -1;
        }
    }
}

void printAnswer()
{
    
}