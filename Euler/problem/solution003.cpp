/*
 * Problem 3: Largest prime factor
 * Find the largest prime factor of 600851475143
 * 最大素因数を求める
 * Auther: takuzoo3868
 * Last Modified: 29/Apr/2017
 */

#include <iostream>
#include <chrono>

using namespace std;

int main() {
    long long num = 600851475143;
    long long factors = 2;
    long long primeFactors;

    // Save measurement start time
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    while (factors * factors < 600851475143) {
        while (num % factors == 0) {
            num = num / factors;
            primeFactors = factors;
        }
        factors += 1;
    }
    cout << primeFactors << endl;

    // Save measurement end time
    end = std::chrono::system_clock::now();
    // Calculation of processing time
    std::chrono::duration<double> elapsed_seconds = end - start;
    // Output in microseconds
    std::cout << "Elapsed time: " << elapsed_seconds.count() << " sec \n";

    return 0;
}
