/*
 * Problem 4: Largest palindrome product
 * Find the largest palindromic number made from the product of two 3 digit numbers
 * 回文数の最大値を求める
 * Auther: takuzoo3868
 * Last Modified: 01/May/2017
 */

#include <iostream>
#include <chrono>

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

int main() {
    // Save measurement start time
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    std::cout << LargestPalindrome(999 * 999) << std::endl;

    // Save measurement end time
    end = std::chrono::system_clock::now();
    // Calculation of processing time
    std::chrono::duration<double> elapsed_seconds = end - start;
    // Output in microseconds
    std::cout << "Elapsed time: " << elapsed_seconds.count() << " sec \n";
    return 0;
}
