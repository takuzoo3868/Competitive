/*
 * Problem 2: Even Fibonacci numbers
 * Sum all even terms in the Fibonacci sequence up to 4,000,000
 * フィボナッチ数列における 4,000,000 までの偶数値の項の総和
 * Auther: takuzoo3868
 * Last Modified: 29/Apr/2017
 */

#include <iostream>
#include <chrono>

using namespace std;

int fibonacci(int n) {
    int f0 = 0;
    int f1 = 1;
    int fn = 0;

    for (int i = 1; i <= n; i++) {
        fn = f0 + f1;
        f0 = f1;
        f1 = fn;
    }
    return fn;
}

int main() {
    int sum = 0;
    int num = 0;

    // Save measurement start time
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    int i = 1;
    while (num <= 4000000) {
        num = fibonacci(i);
        // 偶数値判定
        if (num % 2 == 0) {
            sum = sum + num;
        }
        i++;
    }
    cout << sum << endl;

    // Save measurement end time
    end = std::chrono::system_clock::now();
    // Calculation of processing time
    std::chrono::duration<double> elapsed_seconds = end - start;
    // Output in microseconds
    std::cout << "Elapsed time: " << elapsed_seconds.count() << " sec \n";

    return 0;
}
