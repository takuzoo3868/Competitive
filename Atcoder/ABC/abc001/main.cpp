#include <bits/stdc++.h>

#define OUT(d) std::cout<<d;
#define REP(i, n) for(int i=0; i<(int)(n); ++i)
#define FOR(i, k, n) for(int i=(k);i<(int)(n);++i)

using namespace std;

int main() {
    int m;
    cin >> m;

    if (m < 100) {
        cout << "00" << endl;
    } else if (m <= 900) {
        cout << "0" << (m / 100) << endl;
    } else if (m <= 5000) {
        cout << (m / 100) << endl;
    } else if (m <= 30000) {
        cout << (m / 1000 + 50) << endl;
    } else if (m <= 70000) {
        cout << 80 + (m / 1000 - 30) / 5 << endl;
    } else {
        cout << "89" << endl;
    }

    return 0;
}