#include <bits/stdc++.h>
#define allout(MSG,X)   std::cout<<"\n"<<MSG <<" ";for(auto w:X)std::cout<<w<<" "
using namespace std;

void prob3(){
    vector <int> B {4, 0, 0, 3, 6, 0, 7, 0, 0, 9, 0, 1} ;
    auto coco = remove( B.begin(), B.end(), 0) ;
    B.resize( coco - B.begin()) ;
    allout("Prob3 ", B ) ;
}

void studentCode(){
    vector <int> B {4, 0, 0, 3, 6, 0, 7, 0, 0, 9, 0, 1} ;
    //
    for(int i = 0; i < B.size();){
        if(B[i] == 0)
            B.erase(B.begin() + i);
        else
            i++;
    }
    //
    allout("Prob3 ", B ) ;
}

int main(void)
{
    prob3();
    studentCode();
    return 0;
}