/*
 * Problem 4: Largest palindrome product
 * Find the largest palindromic number made from the product of two 3 digit numbers
 * 回文数の最大値を求める
 * Auther: takuzoo3868
 * Last Modified: 01/May/2017
 */

#include <iostream>

using namespace std;

bool IsPalindrome(long num) {
    std::string strnum = std::to_string(num);
    for (int i = 0; i < strnum.size() / 2; i++) {
        if (strnum[i] != strnum[strnum.size() - i - 1]) return false;
    }
    return true;
}

bool HasTwoThreeDigitFactors(long num) {
    for (int i = 100; i < 999; i++) {
        if (num % i == 0 && num / i < 999 && num / i > 100) return true;
    }
    return false;
}

long LargestPalindrome(long num) {
    for (int i = num; i > 100 * 100; i--) {
        if (IsPalindrome(i) && HasTwoThreeDigitFactors(i)) return i;
    }
    return 0;
}

int solution004() {
    std::cout << LargestPalindrome(999 * 999) << std::endl;
    return 0;
}
