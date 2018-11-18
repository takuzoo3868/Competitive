/*
 * Problem 21: Amicable numbers
 * Sum all the amicable pairs up to 10000
 * 10000未満の友愛数の和
 * Author: takuzoo3868
 * Last Modified: 15/Sep/2017
 */

#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

int sumProperD(int x) {
    int num = 1;
    for (int i = 2; i < sqrt(x); i++) {
        if (!(x % i)) {
            num += i + x / i;
        }
    }
    return num;
}

int main() {
    // Save measurement start time
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    int ans = 0;
    for (int i = 1; i < 10000; i++) {
        if (i == sumProperD(sumProperD(i)) && i != sumProperD(i)) {
            ans += i;
        }
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