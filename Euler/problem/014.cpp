/*
 * Problem 14: Longest Collatz sequence
 * n -> n/2 if n is even
 * n -> 3n +1 if n is odd
 * Which starting number under 1,000,000 produces the longest chain
 * 100万未満のうち最長のコラッツ数列を生成する数
 * Author: takuzoo3868
 * Last Modified: 14/Sep/2017
 */

#include <iostream>
#include <chrono>

#define LIMIT 1000000

inline unsigned int next(unsigned int n) {
    return n % 2 == 0 ? n / 2 : 3 * n + 1;
}

int len(unsigned int n) {
    static int table[LIMIT] = {0, 1};
    if (n < LIMIT) {
        if (table[n] == 0) {
            table[n] = len(next(n)) + 1;
        }
        return table[n];
    } else {
        return len(next(n)) + 1;
    }
}

using namespace std;

int main() {
    // Save measurement start time
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    unsigned int max = 1;
    for (unsigned int n = 2; n < LIMIT; n++) {
        if (len(max) < len(n)) {
            max = n;
        }
    }
    cout << "Max:" << max << " Length:" << len(max) << endl;

    // Save measurement end time
    end = std::chrono::system_clock::now();
    // Calculation of processing time
    std::chrono::duration<double> elapsed_seconds = end - start;
    // Output in microseconds
    std::cout << "Elapsed time: " << elapsed_seconds.count() << " sec \n";

    return 0;
}