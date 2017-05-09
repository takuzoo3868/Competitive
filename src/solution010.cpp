/*
 * Problem 10: Summation of primes
 * Find the sum of all the primes below two million
 * 2000000 以下の全ての素数の和
 * Author: takuzoo3868
 * Last Modified: 08/May/2017
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

#define N 2000000

using namespace std;

// エラトステネスの篩
void sieve(vector<int> &primes, int max) {
    if (max <= 2) {
        primes.push_back(2);
    } else {
        // 設定値の平方根以下の値を約数に持つ合成数を削除
        int max_prev = int(sqrt((double) max));
        sieve(primes, max_prev);

        // 全ての値をtrueで初期化
        vector<bool> arr((unsigned int) (max + 1), true);
        typedef vector<int>::const_iterator CIT;

        // 動的配列にある素数の倍数をふるい落とす
        for (CIT q = primes.begin(); q != primes.end(); ++q) {
            int p = *q;
            for (int k = p; k <= max; k += p)
                arr[k] = false;
        }

        for (int k = max_prev + 1; k <= max; k++) {
            // ふるい残った整数を配列に追加
            if (arr[k])
                primes.push_back(k);
        }
    }
}

int solution010() {
    vector<int> primes; // 素数を格納する動的配列

    sieve(primes, N);
    double sum = accumulate(primes.begin(), primes.end(), 0.0);
    cout << (long long) sum << endl;

    return 0;
}