#include <bits/stdc++.h>

#define OUT(d) std::cout<<d;
#define REP(i, n) for(int i=0; i<(int)(n); ++i)
#define FOR(i, k, n) for(int i=(k); i<(int)(n); ++i)

using namespace std;

double Heron(double a, double b, double c) {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    vector<vector<int> > pos(3, vector<int>(2));
    for (auto& p : pos) {
        for (auto& i : p) {
            cin >> i;
        }
    }

    vector<double> dist(3);
    REP(i, 3) {
        dist[i] = sqrt(pow((pos[(i + 1) % 3][0] - pos[(i + 2) % 3][0]), 2) + pow((pos[(i + 1) % 3][1] - pos[(i + 2) % 3][1]), 2));
    }

    cout << fixed << setprecision(3) << Heron(dist[0], dist[1], dist[2]) << "\n";
    return 0;
}