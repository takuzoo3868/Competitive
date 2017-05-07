/*
 * Problem 2: Even Fibonacci numbers
 * Sum all even terms in the Fibonacci sequence up to 4,000,000
 * フィボナッチ数列における 4,000,000 までの偶数値の項の総和
 * Auther: takuzoo3868
 * Last Modified: 29/Apr/2017
 */

#include <iostream>

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

int solution002() {
    int sum = 0;
    int num = 0;

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

    return 0;
}
