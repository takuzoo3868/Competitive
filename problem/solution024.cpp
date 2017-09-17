/*
 * Problem 24: Lexicographic permutations
 * Find the millionth lexicographic permutation of the digits 0-9
 * 辞書式順列の解法
 * Author: takuzoo3868
 * Last Modified: 17/Sep/2017
 */

#include <iostream>
#include <chrono>

using namespace std;

#define FOR(i) for(int i = 0;i < 10;i++)


int main() {
    // Save measurement start time
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    int count = 0;
    FOR(i) {
        FOR(j) {
            if (i == j) continue;
            FOR(k) {
                if (i == k || j == k) continue;
                FOR(l) {
                    if (i == l || j == l || k == l) continue;
                    FOR(m) {
                        if (i == m || j == m || k == m || l == m) continue;
                        FOR(n) {
                            if (i == n || j == n || k == n || l == n || m == n) continue;
                            FOR(o) {
                                if (i == o || j == o || k == o || l == o || m == o || m == o || n == o) continue;
                                FOR(p) {
                                    if (i == p || j == p || k == p || l == p || m == p || m == p || n == p ||
                                        o == p)
                                        continue;
                                    FOR(q) {
                                        if (i == q || j == q || k == q || l == q || m == q || m == q || n == q ||
                                            o == q || p == q)
                                            continue;
                                        FOR(r) {
                                            if (i == r || j == r || k == r || l == r || m == r || m == r || n == r ||
                                                o == r || p == r || q == r)
                                                continue;
                                            count++;
                                            if (count == 1000000) {
                                                cout << i << j << k << l << m << n << o << p << q << r << endl;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }


    // Save measurement end time
    end = std::chrono::system_clock::now();
    // Calculation of processing time
    std::chrono::duration<double> elapsed_seconds = end - start;
    // Output in microseconds
    std::cout << "Elapsed time: " << elapsed_seconds.count() << " sec \n";

    return 0;
}