#include <iostream>
using namespace std;


int main()
{
    int arr[5];
    int ans[10];

    for(int i = 0; i < 5; i++){
        cin >> arr[i];
        ans[arr[i]]++;
    }

    for(int i = 0; i < 10; i++)
        if(ans[i] == 1)
            cout << i << endl;
}
