/*
 * Problem 27: Quadratic primes
 * Find the product of the coefficients, a and b, for the quadratic expression
 * n^2 + an + b
 * 連続する整数で素数を生成したときに最長の長さとなるときの係数a,bの積
 * Author: takuzoo3868
 * Last Modified: 18/Nov/2018
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define P 1000
#define A 1000
#define B 1000
vector<int> primes;

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    for (int p = 0; p < primes.size() && primes[p] * primes[p] <= n; p++)
        if (n % primes[p] == 0) {
            return false;
        }
    return true;
}

void getPrimes() {
    int sievebound = (P - 1) / 2;
    int calcbound = (int(sqrt(P)) - 1) / 2;
    bool sieve[(P - 1) / 2 + 1] = {0};
    for (int i = 1; i <= calcbound; i++)
        if (!sieve[i])
            for (int j = 2 * i * (i + 1); j <= sievebound; j += 2 * i + 1) {
                sieve[j] = 1;
            }
    for (int i = 1; i <= sievebound; i++)
        if (!sieve[i]) {
            primes.push_back(2 * i + 1);
        }
}

int main() {

    // Save measurement start time
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    getPrimes();
    int longest = 1, product = 0;
    for (int p = 0; p < primes.size(); p++) {
        int b = primes[p];
        for (int a = 1 - b; a < A; a++) {
            int n = 0;
            while (isPrime(n * n + a * n + b)) {
                n++;
            }
            if (n > longest) {
                longest = n;
                product = a * b;
            }
        }
    }
    cout << "Answer is " << product << "\n";

    // Save measurement end time
    end = std::chrono::system_clock::now();
    // Calculation of processing time
    std::chrono::duration<double> elapsed_seconds = end - start;
    // Output in microseconds
    std::cout << "Elapsed time: " << elapsed_seconds.count() << " sec \n";

    return 0;
}