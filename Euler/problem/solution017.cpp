/*
 * Problem 17: Number letter counts
 * How many letters would it take to write all the numbers in words from 1 to 1000
 * 数の英語表記の文字数をカウント
 * Author: takuzoo3868
 * Last Modified: 14/Sep/2017
 */

#include <iostream>
#include <chrono>

using namespace std;

int main() {
    // Save measurement start time
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    // 文字数を格納する配列
    // one, two, three, four, five, six, seven, eight, nine, ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen
    int a[19] = {3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
    // twenty, thirty, forty, fifty, sixty, seventy, eighty, ninety
    int b[8] = {6, 6, 5, 5, 5, 7, 6, 6};

    int count = 0;

    // 20未満までのカウント
    for (int i = 1; i < 20; i++)
        count += a[i - 1];

    // 100未満までのカウント
    for (int i = 20; i < 100; i++) {
        if (i % 10 == 0) {
            count += b[i / 10 - 2];
        } else {
            count += b[i / 10 - 2] + a[i % 10 - 1];
        }
    }

    // 1000未満までのカウント
    for (int i = 100; i < 1000; i++) {
        if (i % 100 == 0) {
            count += a[i / 100 - 1] + 7;
        } else if (i % 100 < 20) {
            count += a[i / 100 - 1] + 7 + 3 + a[i % 100 - 1];
        } else if (i % 10 == 0) {
            count += a[i / 100 - 1] + 7 + 3 + b[i / 10 % 10 - 2];
        } else {
            count += a[i / 100 - 1] + 7 + 3 + a[i % 10 - 1] + b[i / 10 % 10 - 2];
        }
    }

    // 1000 = "one thousand" を追加
    count += 11;
    cout << count << endl;

    // Save measurement end time
    end = std::chrono::system_clock::now();
    // Calculation of processing time
    std::chrono::duration<double> elapsed_seconds = end - start;
    // Output in microseconds
    std::cout << "Elapsed time: " << elapsed_seconds.count() << " sec \n";

    return 0;
}