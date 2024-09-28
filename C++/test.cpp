#include <iostream>
#include <vector>
using namespace std;


int main()
{
    vector<vector<int>> vec(300000);
    for(int i = 0; i < 300000; i++)
        vec[i].push_back(1);

    cout << vec.size() << endl;
    cout << vec.capacity() << endl;
}