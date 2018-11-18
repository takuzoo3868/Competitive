/*
 * Problem 28: Number spiral diagonals
 * the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed
 * e.g. starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral
 *   21 22 23 24 25
 *   20  7  8  9 10
 *   19  6  1  2 11
 *   18  5  4  3 12
 *   17 16 15 14 13
 * 対角線上の数字の和
 * Author: takuzoo3868
 * Last Modified: 18/Nov/2018
 */

#include <iostream>
#include <chrono>

using namespace std;

#define N 1001

int main() {

    // Save measurement start time
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    int sum = 1;
    for (int n = 3; n <= N; n += 2) {
        sum += 4 * n * n - 6 * n + 6;
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