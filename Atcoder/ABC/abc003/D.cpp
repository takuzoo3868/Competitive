#include <bits/stdc++.h>

#define OUT(d) std::cout<<d;
#define TAB std::cout<<"\t";
#define BR std::cout<<"\n";
#define REP(i, n) for(int i=0; i<(int)(n); ++i)
#define FOR(i, k, n) for(int i=(k); i<(int)(n); ++i)

using namespace std;

typedef long long ll;
const int MOD = 1000000007;
ll Factrial(ll n, ll mod) {
    if (n <= 0) {
        return 1;
    }
    return fmod(Factrial(n - 1, mod) * n, mod);
}

ll RepeatSquaring(ll n, ll p, ll mod) {
    if (p == 0) {
        return 1;
    }
    if (p % 2 == 0) {
        ll t = RepeatSquaring(n, p / 2, mod);
        return t * t % mod;
    }
    return n * RepeatSquaring(n, p - 1, mod) % mod;
}

ll Combination(ll n, ll r, ll mod) {
    if (n < r || r < 0) {
        return 0;
    }
    r = min(r, n - r);
    if (r == 0) {
        return 1;
    }
    ll ans = 1;
    ans *= Factrial(n, mod);
    ans %= mod;
    ans *= RepeatSquaring(Factrial(n - r, mod), mod - 2, mod);
    ans %= mod;
    ans *= RepeatSquaring(Factrial(r, mod), mod - 2, mod);
    ans %= mod;
    return ans;
}

int main() {
    int r, c, x, y, d, l;
    cin >> r >> c >> x >> y >> d >> l;
    auto Comb = [&](int _x, int _y) -> ll{return Combination(_x * _y, d, MOD) * Combination(_x * _y - d, l, MOD) % MOD;};
    cout << ((Comb(x, y) + ((x * y != d + l) ? (-2 * Comb(x - 1, y) % MOD - 2 * Comb(x, y - 1) % MOD + 4 * Comb(x - 1, y - 1) % MOD + Comb(x - 2, y) + Comb(x, y - 2) - 2 * Comb(x - 2, y - 1) % MOD - 2 * Comb(x - 1, y - 2) % MOD + Comb(x - 2, y - 2) + MOD) : 0)) * (r - x + 1) % MOD * (c - y + 1) % MOD) << "\n";
    return 0;
}