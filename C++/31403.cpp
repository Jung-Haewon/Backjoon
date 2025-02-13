#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int a, b, c;
    int ans1, ans2;

    cin >> a >> b >> c;

    ans1 = a + b - c;
    ans2 = stoi(to_string(a) + to_string(b)) - c;

    cout << ans1 << endl << ans2 << endl;

    return 0;
}