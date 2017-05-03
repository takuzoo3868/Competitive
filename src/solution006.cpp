/*
 * Problem 6: Sum square difference
 * Find the difference between the sum of squares of the first 100 natural numbers and the square of the sum
 * 自然数における二乗の和と和の二乗の差
 * Author: takuzoo3868
 * Last Modified: 03/May/2017
 */

#include <iostream>

using namespace std;

int solution006() {
    long long a = 0;
    long long b = 0;
    long long diff;

    for (long long num = 1; num <= 100; num++) {
        a = a + num * num;
        b = b + num;
    }
    diff = b*b - a;
    cout << diff << endl;

    return 0;
}