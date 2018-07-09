#include <bits/stdc++.h>

#define OUT(d) std::cout<<d;
#define REP(i, n) for(int i=0; i<(int)(n); ++i)
#define FOR(i, k, n) for(int i=(k); i<(int)(n); ++i)

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int a[n][n];
    REP(i, n) {
        REP(j, n) {
            a[i][j] = 0;
        }
    }
    REP(i, m) {
        int b, c;
        cin >> b >> c;
        a[b - 1][c - 1] = 1;
        a[c - 1][b - 1] = 1;
    }

    int ans = 0;
    FOR(bit, 1, (1 << n)) {
        vector<int> v;
        REP(i, n) {
            if (bit & (1 << i)) {
                v.push_back(i);
            }
        }
        bool flag = true;
        REP(i, v.size()) {
            FOR(j, i + 1, v.size()) {
                if (!a[v[i]][v[j]]) {
                    flag = false;
                }
            }
        }
        if (flag) {
            ans = max(ans, (int)v.size());
        }
    }
    cout << ans << "\n";

    return 0;
}