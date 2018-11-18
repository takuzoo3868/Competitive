/*
 * Problem 6: Sum square difference
 * Find the difference between the sum of squares of the first 100 natural numbers and the square of the sum
 * 自然数における二乗の和と和の二乗の差
 * Author: takuzoo3868
 * Last Modified: 03/May/2017
 */

#include <iostream>
#include <chrono>

using namespace std;

int main() {
    long long a = 0;
    long long b = 0;
    long long diff;

    // Save measurement start time
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    for (long long num = 1; num <= 100; num++) {
        a = a + num * num;
        b = b + num;
    }
    diff = b * b - a;
    cout << diff << endl;

    // Save measurement end time
    end = std::chrono::system_clock::now();
    // Calculation of processing time
    std::chrono::duration<double> elapsed_seconds = end - start;
    // Output in microseconds
    std::cout << "Elapsed time: " << elapsed_seconds.count() << " sec \n";

    return 0;
}