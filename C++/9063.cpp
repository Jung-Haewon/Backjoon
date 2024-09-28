#include <iostream>
using namespace std;

int main()
{
    int minX, maxX, minY, maxY;
    int x, y;
    int n;

    cin >> n >> x >> y;
    minX = x;
    maxX = x;
    minY = y;
    maxY = y;

    for(int i = 1; i < n; i++)
    {
        cin >> x >> y;

        if(minX > x)
            minX = x;
        if(maxX < x)
            maxX = x;
        if(minY > y)
            minY = y;
        if(maxY < y)
            maxY = y;
    }

    int ans = (maxX - minX) * (maxY - minY);
    cout << ans << endl;

    return 0;
}
