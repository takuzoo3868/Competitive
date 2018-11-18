/*
 * Problem 20: Factorial digit sum
 * Find the sum of the digits in the number 100!
 * 階乗の各位の和
 * Author: takuzoo3868
 * Last Modified: 14/Sep/2017
 */

#include <iostream>
#include <chrono>

using namespace std;

int main() {
    // Save measurement start time
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    int ans = 0;
    int num[200] = {};

    num[0] = 1;
    
    for (int i = 1; i <= 100; i++) {
        for (int j = 0; j < 200; j++) {
            num[j] *= i;
        }
        for (int j = 0; j < 200; j++) {
            if (num[j] >= 10) {
                num[j + 1] += num[j] / 10;
                num[j] %= 10;
            }
        }
    }
    
    for (int i = 0; i < 200; i++) {
        ans += num[i];
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