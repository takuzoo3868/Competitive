/* 
 * Find the largest palindromic number made from the product of two 3 digit numbers
 * 回文数の最大値を求める
 * Auther: takuzoo3868
 * Last Modified: 01/May/2017
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string intToString(int numb) {
  stringstream abc;
  abc << numb;
  return abc.str();
}

int check(int n) {
  int i, j;
  string sss = intToString(n);
  
  for (i = 0, j = sss.length() -1 ; i <= j; i++, j--) {
    if (sss[i] != sss[j]) { 
      return 0;
    }
  }
  return 1;
}

int main() {
  int num;
  int max = 0;

  for (int a = 0; a < 1000; a++) {
    for (int b = 0; b < 1000; b++) {
      num = a * b;
      if (check(num) == 1) {
        if (num > max) {
          max = num; 
        }
      }
    }
  }
  cout << max << endl;
  
  return 0;
}
