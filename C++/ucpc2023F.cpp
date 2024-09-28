#include <iostream>
#include <string>
using namespace std;

int n, q;
int arr[1000][1000];
int tmp[1000];

int main()
{
        ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    cin >> n >> q;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            arr[i][j] = n * i + j + 1;

    string order;

    for(int i = 0; i < q; i++)
    {
        cin >> order;

        if(order == "RO")
        {
            for(int i = 0; i < n; i += 2)
                tmp[i] = arr[i][n-1];

            for(int i = 0; i < n; i += 2)
                for(int j = n-1; j > 0; j--)
                    arr[i][j] = arr[i][j-1];

            for(int i = 0; i < n; i += 2)
                arr[i][0] = tmp[i];
        }
        else if(order == "RE")
        {
            for(int i = 1; i < n; i += 2)
                tmp[i] = arr[i][n-1];

            for(int i = 1; i < n; i += 2)
                for(int j = n-1; j > 0; j--)
                    arr[i][j] = arr[i][j-1];

            for(int i = 1; i < n; i += 2)
                arr[i][0] = tmp[i];
        }
        else if(order == "CO")
        {
            for(int i = 0; i < n; i += 2)
                tmp[i] = arr[n-1][i];

            for(int i = 0; i < n; i += 2)
                for(int j = n-1; j > 0; j--)
                    arr[j][i] = arr[j-1][i];

            for(int i = 0; i < n; i += 2)
                arr[0][i] = tmp[i];
        }
        else if(order == "CE")
        {
            for(int i = 1; i < n; i += 2)
                tmp[i] = arr[n-1][i];

            for(int i = 1; i < n; i += 2)
                for(int j = n-1; j > 0; j--)
                    arr[j][i] = arr[j-1][i];

            for(int i = 1; i < n; i += 2)
                arr[0][i] = tmp[i];
        }
        else
        {
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            r1--;
            c1--;
            r2--;
            c2--;
            int tmp = arr[r1][c1];
            arr[r1][c1] = arr[r2][c2];
            arr[r2][c2] = tmp;
        }
    }
        string ans = "";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ans += to_string(arr[i][j]);

            if(j != n - 1)
                ans += " ";
        }
        ans += "\n";
    }
    cout << ans;

    return 0;
}