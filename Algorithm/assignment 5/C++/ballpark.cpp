#include <iostream>
#include <string.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    cout<<n << m;

    int** arr = new int* [n];
    for(int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
        memset(arr[i], 0, sizeof(int)*m);
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            arr[i][j] = 0;
            cout << arr[i][j];
        }
        cout << endl;

    for(int i = 0; i < n; i++)
    {
        delete [] arr[i];
    }
    

    return 0;
}