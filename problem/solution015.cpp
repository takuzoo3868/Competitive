/*
 * Problem 15: Lattice paths
 * Find the number of routes through a 20×20 grid
 * 経路数
 * Author: takuzoo3868
 * Last Modified: 14/Sep/2017
 */

#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

int main() {
    // Save measurement start time
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    // 経路問題に於ける書き込み式に類似した解法
    const int x = 21;
    const int y = 21;

    long long int matrix[x][y];

    for (int i = 0; i < x; i++)
        matrix[i][y - 1] = 1;
    for (int j = 0; j < y; j++)
        matrix[x - 1][j] = 1;

    for (int i = x - 2; i >= 0; i--)
        for (int j = y - 2; j >= 0; j--)
            matrix[i][j] = matrix[i + 1][j] + matrix[i][j + 1];

    cout << matrix[0][0] << endl;

    // Save measurement end time
    end = std::chrono::system_clock::now();
    // Calculation of processing time
    std::chrono::duration<double> elapsed_seconds = end - start;
    // Output in microseconds
    std::cout << "Elapsed time: " << elapsed_seconds.count() << " sec \n";

    return 0;
}


