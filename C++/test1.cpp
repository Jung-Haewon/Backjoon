#include <bits/stdc++.h>
using namespace std;

#define MAX_N 50  // 추가로 고침 2022년 11월
#define D      4

int M[MAX_N][MAX_N];
int C[MAX_N][MAX_N][D];
int N;
int T;

typedef pair<int,pair<pair<int,int>,int> > key_type;

key_type make( int c, int i, int j, int d ) {
    return make_pair( -c, make_pair( make_pair( i, j ), d ) );
}

void move( priority_queue<key_type>& Q, int c, int i, int j, int d ) {
    if( !M[i][j] ) return;
    if( C[i][j][d] <= c ) return;
    Q.push( make( c, i, j, d ) );
    C[i][j][d] = c;
}

int main( void ) {
    if( !( cin >> N >> T     ) )    { cerr << "Invalid input: cannot read N, T" << endl; return 1; }
    if( !( 3 <= N && N <= MAX_N ) ) { cerr << "Invalid input: N=" << N << endl;          return 1; }
    if( !( 2 <= T && T <=  5 ) )    { cerr << "Invalid input: T=" << T << endl;          return 1; }

    for( int i = N; i >= 1; --i ) {
        for( int j = 1; j <= N; ++j ) {
            if( !(cin >> M[i][j] ) )           { cerr << "Invalid input: cannot read M[" << i << "][" << j << "]" << endl; return 1; }
            if( M[i][j] != 0 && M[i][j] != 1 ) { cerr << "Invalid input: M[" << i << "][" << j << "]=" << M[i][j] << endl; return 1; }

            M[i][j] = !M[i][j];
            C[i][j][0] = C[i][j][1] = C[i][j][2] = C[i][j][3] = N*N*(T+1);
        }
    }

    string tmp;
    if( cin >> tmp ) { cerr << "Warning: input not completely consumed. remaining token: " << tmp << endl; }

    priority_queue< key_type > Q;
    // push (1,1) with two directions (UP,RIGHT)
    Q.push( make( 0, 1, 1, 0 ) );
    Q.push( make( 0, 1, 1, 1 ) );
    while( !Q.empty() ) {
        int c = -Q.top().first;
        int i =  Q.top().second.first.first;
        int j =  Q.top().second.first.second;
        int d =  Q.top().second.second;
        Q.pop();

        move( Q, c+1+(d!=0)*T, i+1, j  , 0 ); // UP
        move( Q, c+1+(d!=1)*T, i  , j+1, 1 ); // RIGHT
        move( Q, c+1+(d!=2)*T, i-1, j  , 2 ); // DOWN
        move( Q, c+1+(d!=3)*T, i  , j-1, 3 ); // LEFT

        if( i == N && j == N ) break;
    }

    int answer = min( C[N][N][0], C[N][N][1] );
    cout << (answer==N*N*(T+1)?-1:answer) << endl;

    return 0;
}
