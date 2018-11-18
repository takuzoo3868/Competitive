/*
 * Problem 29: Distinct powers
 * how many distinct terms are in the sequence ...
 * 異なる項の探索
 * Author: takuzoo3868
 * Last Modified: 18/Nov/2018
 */

#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

#define N 100

int powOf(int a) {
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            int pow = 0, temp = a;
            for (; temp % i == 0; temp /= i, pow++);
            if (temp == 1) {
                return pow;
            }
        }
    }
    return 1;
}

int main() {

    // Save measurement start time
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    int overlap[6 + 1] = {0};
    bool used[6 * N + 1] = {0};
    for (int pow = 1; pow < 6 + 1; pow++) {
        for (int b = 2 * pow; b <= N * pow; b += pow) {
            if (used[b]) {
                overlap[pow]++;
            }
            used[b] = 1;
        }
    }
    int sum = 0;
    for (int a = 2; a <= N; a++) {
        sum += N - 1 - overlap[powOf(a)];
    }
    cout << "Answer is " << sum << endl;

    // Save measurement end time
    end = std::chrono::system_clock::now();
    // Calculation of processing time
    std::chrono::duration<double> elapsed_seconds = end - start;
    // Output in microseconds
    std::cout << "Elapsed time: " << fixed << elapsed_seconds.count() << " sec" << std::endl;

    return 0;
}