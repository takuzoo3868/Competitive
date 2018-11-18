/*
 * Problem 9: Special Pythagorean triplet
 * Find the product of the terms of the unique Pythagorean triplet a+b+c = 1000
 * 条件を満たすピタゴラス数(a+b+c = 1000)を求める
 * Author: takuzoo3868
 * Last Modified: 08/May/2017
 */

#include <iostream>
#include <chrono>

#define NUM 1000

using namespace std;

int main() {
    // Save measurement start time
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    for (int a = 1; a < NUM + 1; a++) {
        for (int b = a; b < NUM + 1; b++) {
            for (int c = b; c < NUM + 1; c++) {
                if (a * a + b * b == c * c && a + b + c == NUM) {
                    cout << a * b * c << endl;
                    break;
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