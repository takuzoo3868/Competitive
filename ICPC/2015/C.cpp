
#include<bits/stdc++.h>

#define REP(i,n) for(int i=0; i<(n); i++)
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define ll long long
using namespace std;
typedef pair<int, int> P;

int n;
string s[1024];

int rec(int a, int b, int c) {
    int res = 0;
    if (c) {
        res = 1;
    }
    for (int i = a; i < n && b < s[i].size(); i++) {
        if (s[i][b] == '.') {
            continue;
        }
        int x = s[i][b] - '0';
        if (s[i][b] == '*') {
            x = rec(i + 1, b + 1, 1);
        }
        if (s[i][b] == '+') {
            x = rec(i + 1, b + 1, 0);
        }
        if (c) {
            res *= x;
        } else {
            res += x;
        }
    }
    return res;
}

int main() {
    while (1) {
        cin >> n;
        if (n == 0) {
            break;
        }
        REP(i, n)cin >> s[i];
        cout << rec(0, 0, 0) << endl;
    }
}