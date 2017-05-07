/*
 * Problem 7: 10001st prime
 * Find the 10,001st prime number
 * 10,001番目の素数を出力
 * Author: takuzoo3868
 * Last Modified: 04/May/2017
 */

#include <iostream>
#include <cmath>

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

int solution007() {
    int integer = 0; // 整数を格納
    int count = 0;   // 素数をカウント
    int prime;       // 素数を格納

    while (1) {
        if (IsPrime(integer)) {
            prime = integer;
            count++;
        }
        integer++;
        if (count == ORDINAL) break;
    }
    cout << prime << endl;

    return 0;
}