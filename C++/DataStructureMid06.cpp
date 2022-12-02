#include <bits/stdc++.h>
#define allout(MSG,X)   std::cout<<"\n"<<MSG <<" ";for(auto w:X)std::cout<<w<<" "
using namespace std;

bool myfun (int i, int j) {
    if( abs(i-j) <= 1 ) return(1) ;
    else return(0) ;
}

prob6() {
	vector<int> myvec1 {15,21,21,20,20,31,20,10,10,11,9,9} ;
	vector<int> myvec2 {15,21,21,20,20,31,20,10,10,11,9,9} ;

	unique (myvec1.begin(), myvec1.end());
	allout("> 1. myvec1[]= ", myvec1 ) ;

	auto it=unique (myvec2.begin(), myvec2.end(), myfun);
	myvec2.resize( distance(myvec2.begin(),it) );
	allout("> 2. myvec2[]= ", myvec2) ;
}

int main(void)
{
	prob6();
	return 0;
}