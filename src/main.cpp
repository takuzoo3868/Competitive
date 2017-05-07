/*
 * Select Problem number & output the Answer in terminal
 * Author: takuzoo3868
 * Last Modified: 29/Apr/2017
 */

#include "main.h"
#include <iostream>
#include <chrono>

#define MAX 8 // Maximum problem number solved

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
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    solve(num);

    // Save measurement end time
    end = std::chrono::system_clock::now();
    // Calculation of processing time
    std::chrono::duration<double> elapsed_seconds = end - start;
    // Output in microseconds
    std::cout << "Elapsed time: " << elapsed_seconds.count() << " sec \n";

    return 0;
}