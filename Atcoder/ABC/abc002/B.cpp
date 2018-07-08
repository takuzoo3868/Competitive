#include<iostream>
#include<vector>
#include<algorithm>

#define REP(i, n) for(int i=0; i<(int)(n); ++i)
#define FOR(i, k, n) for(int i=(k);i<(int)(n);++i)

using namespace std;

int main() {
    string W;
    cin >> W;

    REP(i, W.size()) {
        if(W[i] != 'a' && W[i] != 'i' && W[i] != 'u' && W[i] != 'e' && W[i] != 'o') {
            cout << W[i];
        }
    }
    cout << endl;

    return 0;
}