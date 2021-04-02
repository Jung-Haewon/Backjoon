#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct res{
    int a;
    int b;
}res;

struct res cal(int** arr, int n, int total);

int main(){
    ifstream in("free.inp");
    ofstream out("free.out");

    int n;
    in >> n;

    int** arr = new int* [n];
    for(int i = 0; i < n; i++){
        arr[i] = new int[3];
        in >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    struct res ans = cal(arr, n, 0);

    cout << ans.a << " " << ans.b << endl;

    for(int i = 0; i < n; i++)
        delete [] arr[i];
    
    in.close();
    out.close();
    return 0;
}

struct res cal(int** arr, int n, int total)
{
    if(n == 1)
    {
        struct res ret;
        ret.a = arr[0][2];
        ret.b = total + arr[0][1] - arr[0][0] + 1;
        return ret;
    }

    int* tmp = new int[n];
    tmp[0] = 1;
    int tmpCnt = 1;

    bool isOverlap = false;
    struct res challenger;
    struct res current;
    challenger.a = 0;
    challenger.b = 0;

    for(int i = 1; i < n; i++)
    {
        if(arr[0][0] <= arr[i][1] && arr[0][1] >= arr[i][0])
        {
            tmp[i] = 1;
            tmpCnt++;
            bool isOverlap = true;
        }
    }

    if(isOverlap == true)
    {
        int** newArr = new int* [n-1];
        for(int i = 1; i < n; i++)
            newArr[i-1] = arr[i];
        challenger = cal(newArr, n-1, total);
        for(int i = 0; i < n-1; i++)
            delete [] newArr[i];
    }
    if(tmpCnt != n)
    {
        int** newArr = new int* [n-tmpCnt];
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(tmp[i] != 1)
            {
                newArr[cnt] = arr[i];
                cnt++;
            }
        }
        current = cal(newArr, n-1, total + arr[0][1] - arr[0][0] + 1);
        current.a += arr[0][2] - 10;
        for(int i = 0; i < n-tmpCnt; i++)
            delete [] newArr[i];
    }
    else
    {
        current.a = arr[0][2];
        current.b = total + arr[0][1] - arr[0][0] + 1;
    }

    delete [] tmp;

    cout << current.a << " " << challenger.a << endl;

    if(current.a == challenger.a)
        if(current.b < challenger.b)
            return current;
        else
            return challenger;
    else if (current.a > challenger.a)
        return current;
    else
        return challenger;
}