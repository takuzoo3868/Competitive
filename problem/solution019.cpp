/*
 * Problem 19: Counting Sundays
 * How many Sundays fell on the first of the month during the 20th century
 * 20世紀の日曜日をカウント
 * Author: takuzoo3868
 * Last Modified: DD/MM/2017
 */

#include <iostream>
#include <chrono>

using namespace std;

int main() {
    // Save measurement start time
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    int year = 1901;
    int month = 1;
    int monthOfDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int count = 0;

    int numOfDay = 2;

    while(year <= 2000) {
        // うるう年の判定
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
            monthOfDay[1] = 29;
        } else {
            monthOfDay[1] = 28;
        }

        // 各月の日曜日の数をカウント
        while(month <= 12){
            numOfDay += monthOfDay[month - 1];
            if((numOfDay %= 7) == 0)
                count++;
            month++;
        }

        month = 1;
        year++;
    }

    cout << count << endl;

    // Save measurement end time
    end = std::chrono::system_clock::now();
    // Calculation of processing time
    std::chrono::duration<double> elapsed_seconds = end - start;
    // Output in microseconds
    std::cout << "Elapsed time: " << elapsed_seconds.count() << " sec \n";

    return 0;
}