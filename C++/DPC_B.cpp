#include <iostream>
#include <string>
using namespace std;

int main()
{
    string tabub;
    cin >> tabub;

    string ans;

    if(tabub == "fdsajkl;" || tabub == "jkl;fdsa")
        ans = "in-out";
    else if(tabub == "asdf;lkj" || tabub == ";lkjasdf")
        ans = "out-in";
    else if(tabub == "asdfjkl;")
        ans = "stairs";
    else if(tabub == ";lkjfdsa")
        ans = "reverse";
    else
        ans = "molu";

    cout << ans << endl;

    return 0;
}
