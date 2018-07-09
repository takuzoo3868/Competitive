#include <bits/stdc++.h>

#define OUT(d) std::cout<<d;
#define REP(i, n) for(int i=0; i<(int)(n); ++i)
#define FOR(i, k, n) for(int i=(k); i<(int)(n); ++i)

using namespace std;

vector<int> imos(289, 0); // 12 * 24 + 1

int main() {
    int n;
    cin >> n;
    REP(i, n) {
        int s, e;
        char tmp;
        cin >> s >> tmp >> e;
        imos[s / 100 * 12 + s % 100 / 5]++;
        imos[e / 100 * 12 + (e % 100 + 4) / 5]--;
    }

    FOR(i, 1, 289) {
        imos[i] += imos[i - 1];
    }

    REP(i, 289) {
        if (imos[i] > 0 && (i == 0 || imos[i - 1] == 0)) {
            cout << setw(2) << setfill('0') << (i * 5) / 60;
            cout << setw(2) << setfill('0') << (i * 5) % 60 << '-';
        } else if ((i != 0 && imos[i] == 0 && imos[i - 1] > 0) || (i == 288 && imos[i] > 0)) {
            cout << setw(2) << setfill('0') << (i * 5) / 60;
            cout << setw(2) << setfill('0') << (i * 5) % 60 << "\n";
        }
    }
    return 0;
}