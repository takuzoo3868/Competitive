/*
 * Problem 1: Multiples of 3 and 5
 * Find the sum of all the multiples of 3 or 5 below 1000
 * 1000 未満の 3 か 5 の倍数の和
 * Author: takuzoo3868
 * Last Modified: 29/Apr/2017
 */

#include <iostream>

using namespace std;

int solution001() {
    int sum = 0;

    for (int i = 1; i < 1000; ++i) {
        if (!(i % 3) || !(i % 5)) {
            sum += i;
        }
    }
    cout << sum << endl;

    return 0;
}
