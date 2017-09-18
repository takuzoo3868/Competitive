/*
 * Problem 25: 1000-digit Fibonacci number
 * Find the index of the first term in the Fibonacci sequence
 * 1000桁になる最初のフィボナッチ数列の項
 * Author: takuzoo3868
 * Last Modified: 17/Sep/2017
 */

#include <iostream>
#include <chrono>

using namespace std;

int main() {
    // Save measurement start time
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    int ans = 0;
    int a[1000] = {};
    int b[1000] = {};
    int tmp[1000] = {};

    a[0] = 1;
    for (int i = 0; !ans; i++) {
        for (int j = 0; j < 1000; j++) {
            tmp[j] = a[j];
            a[j] = b[j];
            b[j] += tmp[j];
        }

        for (int j = 0; j < 1000; j++) {
            if (a[j] >= 10) {
                a[j + 1] += a[j] / 10;
                a[j] %= 10;
            }
        }
        if (a[999]) ans = i;
    }
    cout << ans << endl;

    // Save measurement end time
    end = std::chrono::system_clock::now();
    // Calculation of processing time
    std::chrono::duration<double> elapsed_seconds = end - start;
    // Output in microseconds
    std::cout << "Elapsed time: " << elapsed_seconds.count() << " sec \n";

    return 0;
}