#include <bits/stdc++.h>

#define OUT(d) std::cout<<d;
#define REP(i, n) for(int i=0; i<(int)(n); ++i)
#define FOR(i, k, n) for(int i=(k); i<(int)(n); ++i)

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    cout << max(a, b) << "\n";
    return 0;
}