/*
 * Problem 5: Smallest multiple
 * What is the smallest number evenly divisible by 1 up to 20
 * 1 から 20で割り切れる最小の倍数を求める
 * Auther: takuzoo3868
 * Last Modified: 02/May/2017
 */

#include <iostream>
#include <chrono>

using namespace std;

// greatest common divisor: 最大公約数
long gcd(long a, long b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// least common multiple: 最小公倍数
long lcm(long a, long b) {
    return a * (b / gcd(a, b));
}

int main() {
    long LCM = 20;

    // Save measurement start time
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    for (long num = LCM - 1; num > 1; --num) {
        LCM = lcm(LCM, num);
    }
    cout << LCM << endl;

    // Save measurement end time
    end = std::chrono::system_clock::now();
    // Calculation of processing time
    std::chrono::duration<double> elapsed_seconds = end - start;
    // Output in microseconds
    std::cout << "Elapsed time: " << elapsed_seconds.count() << " sec \n";

    return 0;
}
