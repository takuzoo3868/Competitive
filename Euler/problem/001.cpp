/*
 * Problem 1: Multiples of 3 and 5
 * Find the sum of all the multiples of 3 or 5 below 1000
 * 1000 未満の 3 か 5 の倍数の和
 * Author: takuzoo3868
 * Last Modified: 29/Apr/2017
 */

#include <iostream>
#include <chrono>

using namespace std;

int main() {
    int sum = 0;

    // Save measurement start time
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    for (int i = 1; i < 1000; ++i) {
        if (!(i % 3) || !(i % 5)) {
            sum += i;
        }
    }
    cout << sum << endl;

    // Save measurement end time
    end = std::chrono::system_clock::now();
    // Calculation of processing time
    std::chrono::duration<double> elapsed_seconds = end - start;
    // Output in microseconds
    std::cout << "Elapsed time: " << elapsed_seconds.count() << " sec \n";

    return 0;
}
