/*
 * Problem 16: Power digit sum
 * Calculate the sum of the digits
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

    const int n = 1000;

    //multiply about 3 times that increase a digit
    const int num = n / 3;
    int a[num] = {2};
    int size = 1;
    int carry = 0;
    int sum = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < size; j++) {
            a[j] = a[j] * 2 + carry;
            if (a[j] > 9) {
                a[j] %= 10;
                carry = 1;
                if (j + 1 == size)
                    size++;
            } else {
                carry = 0;
            }
        }
    }

    for (int i = size - 1; i >= 0; i--) {
        sum += a[i];
        cout << a[i];
    }

    cout << ": sum = " << sum << endl;

    // Save measurement end time
    end = std::chrono::system_clock::now();
    // Calculation of processing time
    std::chrono::duration<double> elapsed_seconds = end - start;
    // Output in microseconds
    std::cout << "Elapsed time: " << elapsed_seconds.count() << " sec \n";

    return 0;
}