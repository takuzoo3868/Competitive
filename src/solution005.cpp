/*
 * Problem 5: Smallest multiple
 * What is the smallest number evenly divisible by 1 up to 20
 * 1 から 20で割り切れる最小の倍数を求める
 * Auther: takuzoo3868
 * Last Modified: 02/May/2017
 */

#include <iostream>

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

int solution005() {
    long LCM = 20;
    for (long num = LCM - 1; num > 1; --num) {
        LCM = lcm(LCM, num);
    }
    cout << LCM << endl;

    return 0;
}
