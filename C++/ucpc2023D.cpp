#include <iostream>
#include <string>
using namespace std;

void scanData();
void solveProblem();
void printAnswer();

char arr[500][500];
int n, m, k;
char ansArr[500][500];
int maxNum[500][500];
int partAlphabetNum[500][500][26];
int fixCnt;

int main()
{
    scanData();
    solveProblem();
    printAnswer();

    return 0;
}

void scanData()
{
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
}

void solveProblem()
{
    int partNumN = n / k;
    int partNumM = m / k;
    int splitNum = partNumM * partNumN;

    for(int y = 0; y < partNumN; y++){
        for(int x = 0; x < partNumM; x++){
            for(int i = k * y; i < k * y + k; i++){
                for(int j = k * x; j < k * x + k; j++){
                    partAlphabetNum[i - k * y][j - k * x][arr[i][j] - 65]++;
                    //cout << arr[i][j] << endl;
                }
            }
        }
    }

    /*
    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            cout << "i: " << i << " j: " << j << endl;
            for(int a = 0; a < 26; a++)
                cout << char(a + 65) << ": " << partAlphabetNum[i][j][k] << endl;
        }
    }
    */

    for(int i = 0; i < k; i++)
        for(int j = 0; j < k; j++)
            maxNum[i][j] = 0;

    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < k; j++)
        {
            for(int a = 0; a < 26; a++)
            {
                if(partAlphabetNum[i][j][a] > maxNum[i][j])
                {
                    maxNum[i][j] = partAlphabetNum[i][j][a];
                    ansArr[i][j] = char(a + 65);
                }
            }
        }
    }

    for(int i = 0; i < k; i++)
        for(int j = 0; j < k; j++)
            fixCnt += splitNum - maxNum[i][j];
}

void printAnswer()
{
    string ans = to_string(fixCnt) + "\n";

    /*
    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++)
            ans += ansArr[i][j];
        ans += "\n";
    }
    */

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            ans += ansArr[i % k][j % k];
        }
        ans += "\n";
    }

    cout << ans;
}