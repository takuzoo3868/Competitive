/*
 * Problem 26: Reciprocal cycles
 * Find d < 1000 such that 1/d contains the longest recurring cycle
 * 小数部の循環節が最も長くなる逆数
 * Author: takuzoo3868
 * Last Modified: 18/Sep/2017
 */

#include <iostream>
#include <chrono>
#include <map>

using namespace std;

int cycle_length(int d) {
    map<int, int> r;
    int n = 1, i = 1;
    while (n != 0) {
        n = (10 * n) % d;
        if (r.count(n) == 1)
            break;
        r[n] = i++;
    }
    return n == 0 ? 0 : i - r[n];
}

int main() {

    // Save measurement start time
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    int lmax = 0, d = 0;
    for (int i = 2; i < 1000; i++) {
        int l = cycle_length(i);
        if (l > lmax) {
            lmax = l;
            d = i;
        }
    }
    cout << "Longest cycle = " << lmax << ", for d = " << d << endl;

    // Save measurement end time
    end = std::chrono::system_clock::now();
    // Calculation of processing time
    std::chrono::duration<double> elapsed_seconds = end - start;
    // Output in microseconds
    std::cout << "Elapsed time: " << elapsed_seconds.count() << " sec \n";

    return 0;
}