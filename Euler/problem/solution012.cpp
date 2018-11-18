/*
 * Problem 12: Highly divisible triangular number
 * Calculate the value of the first triangular number to have over 500 divisors
 * 500個より多く約数をもつ最初の三角数:高度整除三角数
 * Author: takuzoo3868
 * Last Modified: 01/Jul/2017
 */

#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

int main() {
    unsigned long long int i = 1;
    unsigned long long int sum = 0;

    // Save measurement start time
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    while (1) {
        sum += i;
        int numD = 2;

        for (unsigned long long int n = 2; n < sqrt(sum); ++n)
            if (sum % n == 0)
                numD += 2;

        if (numD > 500) {
            cout << sum << endl;
            break;
        }
        ++i;
    }

    // Save measurement end time
    end = std::chrono::system_clock::now();
    // Calculation of processing time
    std::chrono::duration<double> elapsed_seconds = end - start;
    // Output in microseconds
    std::cout << "Elapsed time: " << elapsed_seconds.count() << " sec \n";

    return 0;
}