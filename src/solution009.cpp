/*
 * Problem 9: Special Pythagorean triplet
 * Find the product of the terms of the unique Pythagorean triplet a+b+c = 1000
 * 条件を満たすピタゴラス数(a+b+c = 1000)を求める
 * Author: takuzoo3868
 * Last Modified: 08/May/2017
 */

#include <iostream>

#define NUM 1000

using namespace std;

int solution009() {
    for (int a = 1; a < NUM + 1; a++) {
        for (int b = a; b < NUM + 1; b++) {
            for (int c = b; c < NUM + 1; c++) {
                if (a * a + b * b == c * c && a + b + c == NUM) {
                    cout << a * b * c << endl;
                    break;
                }
            }
        }
    }
    return 0;
}