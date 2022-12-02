#include <bits/stdc++.h>
#define allout(MSG,X)   std::cout<<"\n"<<MSG <<" ";for(auto w:X)std::cout<<w<<" "
using namespace std;

void prob1(){
    vector< vector<int> > \
      myv = {{11,22,8,9}, {33,55,66}, {55, 76}, {-25},{}} ;
    cout << "\n Out1 = " << myv[0][1] ;
    cout << "\n Out2 = " << myv[2][0] ;
    cout << "\n Out3 = " << myv[1].size() + myv.size() ;
}

void prob2(){
    array< array<int,4>, 3> X {{{1,2,3,4}, {5,6}, {9,10,11,12}} };

    cout << "\n p21 = " << X[2][3] ;
    cout << "\n p22 = " << X[1][3] ;
    cout << "\n p23 = " << X[1].size() + X.size() ;
    int S = 0 ;
    for(int i=0 ; i<3; ++i) S += X[i].back() ;
    cout << "\n p24 = " << S ;
}


void prob3(){
    vector <int> B {4, 0, 0, 3, 6, 0, 7, 0, 0, 9, 0, 1} ;

    auto coco = remove( B.begin(), B.end(), 0) ;
    B.resize( coco - B.begin()) ;
    allout("Prob3 ", B ) ;
}

typedef vector<vector<int>> dvec ;
void prob4(){
    dvec v1 = { {12}    ,  {33, 33}, {66}, {0,1  },{1} } ;
    dvec v2 = { {12, 22},  {33, 32}, {67}, {0,1,2},{2} } ;
    dvec v3 = { {11, 22},  { }                    ,{3} } ;
    dvec v4 = { {12, 22},  {33}    , {67}         ,{4} } ;
    dvec v5 = { { }     ,  {32}    ,               {5} } ;
    dvec v6 = { {12, 22},  { { } } , {66}         ,{6} } ;
    dvec v7 = { {12, 22},  {     } , {65}         ,{7} } ;
    vector<dvec> Allvec = { v1, v2, v3, v4, v5, v6, v7 };

    sort( Allvec.begin(), Allvec.end() ) ;
    for( auto w : Allvec ) {
         allout("> ", w.back()) ;
    }
}

void prob5(){
    vector <int> Z {1,2,3} ;
    int S = 0, T=0 ;
    // 이 상황에서 Z.capacity() = 3 ;
    for(int i=1; i<=30; i++){
        Z.push_back(i) ;
        T += Z.size( );
        cout << "\n Z.size() = " << Z.size( ) << " Z.capa() " << Z.capacity() ;
        S += Z.capacity( );
    }
    cout << "T= " << T << " , S= " << S ;
}

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

template <typename T>
ostream & operator<<(ostream & os, stack<T> my_stack) {
    //Call by value로 stack을 받아와 copy해서 출력하고 버림.
    cout<< "\n Stack Top : " ;
    while(!my_stack.empty()) { //body
        os << "\n -- " << my_stack.top() ;
        my_stack.pop();
    }
    cout<< "\n Stack Bottom : " ;
    return os; // end of function
}

stack<int> Reverse_Stack( stack<int> X){
    vector<int> M ;
    stack <int> T ;
    int temp ;
    while( !X.empty()){
          temp = X.top();
          M.push_back( temp );
          X.pop( );
    }
    for(auto w : M ) T.push(w) ;
    return(T) ;
}



void prob7(){
    stack<int> S, T;
    for(auto w : {1,2,3,4,5,6}) S.push(w) ;
    T = Reverse_Stack( S );
    cout << S;
    cout << T;
}

#define N 9
int GetM(int i, int j) {
  int k ;
  if((i+j)%2 == 1 ) return(0);
  k = (i-1)*N + j ;
  return( (int)(k+1)/2 ) ;
}

void prob8(){
    for(int i=1; i<= N ; i++ ){
        for(int j=1; j<= N ; j++ ){
           if( (i+j)%2 == 0)
           printf("\n (%d,%d) = L index: %d",i,j, GetM(i,j)) ;
        }
    }
}


void showvv( vector< vector<int> > Q ){
    int i,j,k ;
    i = j = 0 ;
    cout << "\n -showvv() ---- \n" ;
    for( auto U : Q ){
        for( auto v : U ) {
            printf(" %3d", v) ;
            j++ ;
        }
        cout << "\n";
        i++; j=0 ;
    }
} // end of showit( )

// 이중 vector에서 vector의 vector의 첫 원소를 그 앞 vector 뒤로 하나씩
// 옮기는 작업.
void prob9(){
    vector< vector<int>> X { {3,4,5}, {2,3}, {6}, {10,11,12,13}, {22,23} } ;
    int tmp ;
    showvv( X ) ;
    vector<int>::iterator vit ;
    for(auto it=X.begin()+1; it!= X.end(); it++){
            tmp = (it)->front();
            (it)->erase( (it)->begin() );
            (it-1)->push_back( tmp ) ;
    }

    auto it = X.begin();
    tmp = (it)->front();
    (it)->erase( (it)->begin() );
    (X.end()-1)->push_back( tmp ) ;

    showvv( X ) ;

} // end of prob10( )

void printQ( queue<float> T ) {
    cout << "\n Q[]의 내부: " ;
    while( !T.empty()){
        cout << T.front( ) << " " ;
        T.pop( ) ;
    }

} // end of printQ( )

void prob10(){
    deque<float> D1 {2.3, 5.1, 7.3, 0.5, 9.6, 4.4, 0.7} ;
    deque<float> D2 {15.1, 32.5, -12.3 , 54.6 } ;
    queue<float> Q1(D1), Q2(D2) ;

    int s1, s2 ;
    float ftem;
    //printQ( Q1 );
    //printQ( Q2 );
    s1 = Q1.size() ;
    s2 = Q2.size() ;
    for(int i=1; i<=s1; i++){  // while loop으로 풀어도 됨.
            ftem = Q1.front() ;
            Q1.pop( ) ;
            Q2.push(ftem) ;
    }
    for(int i=1; i<=s2; i++){
            ftem = Q2.front() ;
            Q2.pop( ) ;
            Q1.push(ftem) ;
    }
    printQ( Q1 );
    printQ( Q2 );
} // end of prob11( )

int main () {
    prob1();
    prob2();
    prob3();
    prob4();
    prob5();
    prob6();
    prob7();
    prob8();
    prob9();
    prob10();

  return 0;

}
