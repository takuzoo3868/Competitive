/*
 * Problem 23: Non-abundant sums
 * Find the sum of all positive integers that cannot be written as the sum of two abundant numbers
 * 2つの過剰数の和で書き表せない正の整数の総和
 * Author: takuzoo3868
 * Last Modified: 17/Sep/2017
 */

#include <iostream>
#include <chrono>
#include <set>
#include <cmath>

using namespace std;

int getDivisorsSum(int n) {
    int sum = 0;
    int mi = static_cast<int>(sqrt(n));

    for (int i = 1; i <= mi; i++) {
        if (n % i == 0) {
            sum += (i + n / i);
        }
    }

    if (mi * mi == n) {
        sum -= mi;
    }
    return sum - n;
}

int main() {
    // Save measurement start time
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    const int Limit = 28123;

    // int 型の順序付集合
    set<int> s;
    set<int>::iterator p, pp;

    bool abundantsSums[Limit] = {false};

    int sum = 0;
    for (int i = 1; i <= Limit; i++) {
        if (getDivisorsSum(i) > i)
            s.insert(i);
        sum += i;
    }

    int abundantsSum = 0;
    for (p = s.begin(); p != s.end(); p++) {
        for (pp = p; pp != s.end(); pp++) {
            int temp = *p + *pp;
            if (temp <= Limit && !abundantsSums[temp - 1]) {
                abundantsSum += temp;
                abundantsSums[temp - 1] = true;
            }
        }
    }

    cout << sum - abundantsSum << endl;

    // Save measurement end time
    end = std::chrono::system_clock::now();
    // Calculation of processing time
    std::chrono::duration<double> elapsed_seconds = end - start;
    // Output in microseconds
    std::cout << "Elapsed time: " << elapsed_seconds.count() << " sec \n";

    return 0;
}