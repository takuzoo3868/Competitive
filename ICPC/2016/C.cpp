#include<bits/stdc++.h>
using namespace std;

int Solve(const int m, int n) {
    long long int MAX_YEAR = 7368792;
    vector<bool> year(MAX_YEAR, false);

    int idx = m;
    while (n--) {
        while (year[idx]) {
            ++idx;
        }
        for (int i = 1; i * idx < MAX_YEAR; ++i) {
            year[i * idx] = true;
        }
    }
    while (year[idx]) {
        ++idx;
    }

    return idx;
}

int main() {
    cin.tie(0);

    int m, n;
    while (cin >> m >> n, m) {
        cout << Solve(m, n) << '\n';
    }

    return 0;
}