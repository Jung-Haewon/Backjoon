#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int min(int a, int b);
int min(int a, int b, int c);

int main(){
    ifstream in("ballpark.inp");
    ofstream out("ballpark.out");

    int n, m;
    string str;
    in >> n >> m;

    getline(in, str);

    int** fArr = new int* [n];
    for(int i = 0; i < n; i++)
    {
        fArr[i] = new int[m];
        for(int j = 0; j < m; j++)
            fArr[i][j] = min(n-i, m-j);
    }

    for(int i = n-1; i >= 0; i--)
    {
        getline(in, str);
        for(int j = 0; j < m; j++)
            if(str[j] == '1')
                fArr[i][j] = 0;
    }

    int cnt = 0, big = 0;
    string ans = "";
    for(int i = n-2; i >= 0; i--)
    {
        for(int j = m-2; j >= 0; j--)
        {
            if(fArr[i][j] != 0)
                fArr[i][j] = min(fArr[i][j+1], fArr[i+1][j], fArr[i+1][j+1]) + 1;
            if(big < fArr[i][j])
            {
                big = fArr[i][j];
                cnt = 1;
            }
            else if(big == fArr[i][j])
                cnt += 1;
        }
    }

    for(int j = 0; j < m; j++)
    {
        for(int i = 0; i < n; i++)
        {
            if(fArr[i][j] == big)
                ans += to_string(j+1) + " " + to_string(i+1) + "\n";
        }
    }

    string ansStr = to_string(big) + " " + to_string(cnt) + "\n";
    out.write(ansStr.c_str(), ansStr.size());
    out.write(ans.c_str(), ans.size());

    for(int i = 0; i < n; i++)
        delete [] fArr[i];
    
    in.close();
    out.close();
    return 0;
}

int min(int a, int b)
{
    if(a < b)
        return a;
    else
        return b;
}

int min(int a, int b, int c)
{
    if(a <= b && a <= c)
        return a;
    else if(b <= a && b <= c)
        return b;
    else
        return c;
}