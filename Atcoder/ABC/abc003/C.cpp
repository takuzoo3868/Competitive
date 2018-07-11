#include <bits/stdc++.h>

#define OUT(d) std::cout<<d;
#define TAB std::cout<<"\t";
#define BR std::cout<<"\n";
#define REP(i, n) for(int i=0; i<(int)(n); ++i)
#define FOR(i, k, n) for(int i=(k); i<(int)(n); ++i)

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    priority_queue<int> pq;
    REP(i, n) {
        int r;
        cin >> r;
        pq.push(r);
    }

    double ans = 0.0;
    REP(i, k) {
        ans += 1.0 * pq.top() / pow(2, i + 1);
        pq.pop();
    }

    cout << fixed << setprecision(6) << ans << "\n";
    return 0;
}