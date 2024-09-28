#include <iostream>
using namespace std;

int t, n;
int arr[1000001];

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    for(int i = 0; i < t; i++)
    {
        long long ans = 0;
        int best = 0;
        cin >> n;

        for(int j = 0; j < n; j++)
            cin >> arr[j];

        for(int j = n - 1; j >= 0; j--)
        {
            if(best < arr[j])
                best = arr[j];
            else
                ans += best - arr[j];
        }

        cout << ans << "\n";
    }

    return 0;
}