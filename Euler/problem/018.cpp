/*
 * Problem 18: Maximum path sum I
 * Find the maximum total from top to bottom of the triangle below
 * 最大経路の和の探索
 * Author: takuzoo3868
 * Last Modified: 14/Sep//2017
 */

#include <iostream>
#include <chrono>

#define N 120
#define height 15

using namespace std;

void maxPathSum(int a[], int p[], int floor, int n) {
    if (floor == height - 1) {
        p[n] = a[n];
    } else {
        if (p[n + floor + 1] == 0)
            maxPathSum(a, p, floor + 1, n + floor + 1);
        if (p[n + floor + 2] == 0)
            maxPathSum(a, p, floor + 1, n + floor + 2);
        p[n] = a[n] + (p[n + floor + 1] > p[n + floor + 2]? p[n + floor + 1]:p[n + floor + 2]);
    }
}

int main() {
    // Save measurement start time
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    int a[N] = {
            75,
            95, 64,
            17, 47, 82,
            18, 35, 87, 10,
            20, 4, 82, 47, 65,
            19, 1, 23, 75, 3, 34,
            88, 2, 77, 73, 7, 63, 67,
            99, 65, 4, 28, 6, 16, 70, 92,
            41, 41, 26, 56, 83, 40, 80, 70, 33,
            41, 48, 72, 33, 47, 32, 37, 16, 94, 29,
            53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14,
            70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57,
            91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48,
            63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31,
            4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23,
    };

    int p[N] = {0};

    maxPathSum(a, p, 0, 0);
    cout << p[0] <<  endl;

    // Save measurement end time
    end = std::chrono::system_clock::now();
    // Calculation of processing time
    std::chrono::duration<double> elapsed_seconds = end - start;
    // Output in microseconds
    std::cout << "Elapsed time: " << elapsed_seconds.count() << " sec \n";

    return 0;
}
