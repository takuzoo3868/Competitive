/*
 * Select Problem number & output the Answer in terminal
 * Author: takuzoo3868
 * Last Modified: 29/Apr/2017
 */

#include "main.h"
#include <iostream>
#include <chrono>

#define MAX 5 // Maximum problem number solved

using namespace std;

int main() {
    // Select problem
    int num;
    while (1) {
        cout << "Select the Problem number:";
        cin >> num;
        if (1 <= num && num <= MAX) break;
    }

    // Save measurement start time
    auto start = std::chrono::system_clock::now();

    solve(num);

    // Save measurement end time
    auto end = std::chrono::system_clock::now();
    // Calculation of processing time
    auto dur = end - start;
    auto micro = std::chrono::duration_cast<std::chrono::microseconds>(dur).count();
    // Output in microseconds
    std::cout << "Elapsed time: " << micro << " micro sec \n";

    return 0;
}
