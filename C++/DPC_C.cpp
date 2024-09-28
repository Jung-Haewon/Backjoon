#include <iostream>
using namespace std;

int main()
{
    int n;
    int ans = 0;
    cin >> n;

    if(n < 3)
        ans = 1;
    else if(n < 6)
        ans = 2;
    else
        ans = 3;

    cout << ans << endl;

    return 0;
}