/*
 * Problem 7: 10001st prime
 * Find the 10,001st prime number
 * 10,001番目の素数を出力
 * Author: takuzoo3868
 * Last Modified: 04/May/2017
 */

#include <iostream>
#include <cmath>
#include <chrono>

#define ORDINAL 10001

using namespace std;

bool IsPrime(int num) {
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false;

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int integer = 0; // 整数を格納
    int count = 0;   // 素数をカウント
    int prime;       // 素数を格納

    // Save measurement start time
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    while (1) {
        if (IsPrime(integer)) {
            prime = integer;
            count++;
        }
        integer++;
        if (count == ORDINAL) break;
    }
    cout << prime << endl;

    // Save measurement end time
    end = std::chrono::system_clock::now();
    // Calculation of processing time
    std::chrono::duration<double> elapsed_seconds = end - start;
    // Output in microseconds
    std::cout << "Elapsed time: " << elapsed_seconds.count() << " sec \n";

    return 0;
}