/*
 * Problem 30: Digit fifth powers
 * Find the sum of all the numbers that can be written as the sum of fifth powers of their digits
 * 各桁を5乗した数の和が元の数と一致するような数の総和
 * Author: takuzoo3868
 * Last Modified: 18/Nov/2018
 */

#include <iostream>
#include <chrono>

using namespace std;

int main() {

    // Save measurement start time
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    long int fifth[10];
    for (int n = 0; n < 10; n++) {
        fifth[n] = n * n * n * n * n;
    }
    long int ans = 0;
    // 6 digits: 6*9^5 = 354294 --> 6-digits, OK.
    // 7 digits: 7*9^5 = 413343 --> 6-digits, NG. 7 digits are NOT availavle.
    // 2 to 354294 (maximum sum for 6 digits)
    for (int n = 10; n < 354295; n++) {
        long int num = n, sum = 0;
        for (; num > 0; num /= 10) {
            sum += fifth[num % 10];
        }
        if (n == sum) {
            ans += n;
        }
    }
    cout << "Answer is " << ans << endl;

    // Save measurement end time
    end = std::chrono::system_clock::now();
    // Calculation of processing time
    std::chrono::duration<double> elapsed_seconds = end - start;
    // Output in microseconds
    std::cout << "Elapsed time: " << fixed << elapsed_seconds.count() << " sec" << std::endl;

    return 0;
}