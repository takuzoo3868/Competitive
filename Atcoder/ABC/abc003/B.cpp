#include <bits/stdc++.h>

#define OUT(d) std::cout<<d;
#define TAB std::cout<<"\t";
#define BR std::cout<<"\n";
#define REP(i, n) for(int i=0; i<(int)(n); ++i)
#define FOR(i, k, n) for(int i=(k); i<(int)(n); ++i)
#define ATCODER(c) (c=='a' || c=='t' || c=='c' || c=='o' || c=='d' || c=='e' || c=='r')

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    REP(i, s.size()) {
        if (s[i] == t[i]) {
            continue;
        }
        if ((s[i] == '@' && ATCODER(t[i])) || (t[i] == '@' && ATCODER(s[i]))) {
            continue;
        }
        cout << "You will lose\n";
        return 0;
    }

    cout << "You can win\n";
    return 0;
}