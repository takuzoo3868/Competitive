#include <bits/stdc++.h>

#define OUT(d) std::cout<<d;
#define REP(i, n) for(int i=0; i<(int)(n); ++i)
#define FOR(i, k, n) for(int i=(k); i<(int)(n); ++i)

using namespace std;

int main() {
    int Deg;
    float Dis;
    int W = 0;
    cin >> Deg >> Dis;

    string dir[17] = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW", "N"};
    int w[12] = {3, 13, 18, 21, 25, 28, 31, 33, 36, 37, 40, 42};
    Deg += 112;
    Dis = roundf(Dis * 10 / 60);

    REP(i, 13) {
        Dis -= w[i];
        if (Dis < 0) {
            W = i;
            break;
        }
    }

    if (W == 0) {
        cout << "C" << " " << 0 << endl;
    } else {
        cout << dir[Deg / 225] << " " << W << endl;
    }
    return 0;
}