#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
typedef tuple<string, char, tuple<int, float, int>> ids;

vector<ids> Rank;

bool cmpB(ids a, ids b) {
    return get<0>(get<2>(a)) > get<0>(get<2>(b));
}

bool cmpD(ids a, ids b) {
    if (get<0>(get<2>(a)) == get<0>(get<2>(b)))
        return get<2>(get<2>(a)) > get<2>(get<2>(b));
}

bool cmpS(ids a, ids b) {
    if (get<0>(get<2>(a)) == get<0>(get<2>(b)))
        if (get<2>(get<2>(a)) == get<2>(get<2>(b)))
            return get<1>(get<2>(a)) < get<1>(get<2>(b));
}

bool cmpG(ids a, ids b) {
    return get<1>(a) == get<1>(b);
}

void getMusic() {
    char G; string T;
    int B, D; float S;
    cin >> T >> G >> B >> S >> D;
    Rank.push_back(make_tuple(T, G, make_tuple(B, S, D)));
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        getMusic();
    }

    sort(Rank.begin(), Rank.end(), cmpB);
    stable_sort(Rank.begin(), Rank.end(), cmpD);
    stable_sort(Rank.begin(), Rank.end(), cmpS);

    for(int i = 0; i < N-1; i++) {
        if(cmpG(Rank[i], Rank[i+1])) {
            for(int j = i; j < N; j++) {
                if(!cmpG(Rank[i], Rank[j])) {
                    ids buf = Rank[j];
                    Rank.erase(Rank.begin()+j);
                    Rank.insert(Rank.begin()+i+1, buf);
                    break;
                }
            }
        }
    }

    //for(auto iter = Rank.begin(); iter!= Rank.end(); iter++) {
    //    cout << get<0>(*iter) << "\t\t" << get<1>(*iter) << "\t" << get<0>(get<2>(*iter)) << "\t" << get<1>(get<2>(*iter)) << "\t" << get<2>(get<2>(*iter)) << endl;
    //}
    cout << get<0>(Rank[M-1]);
}