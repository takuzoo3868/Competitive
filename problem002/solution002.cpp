/* 
 * Sum all even terms in the Fibonacci sequence up to 4,000,000
 * フィボナッチ数列における 4,000,000 までの偶数値の項の総和
 * Auther: takuzoo3868
 * Last Modified: 29/Apr/2017
 */

#include<iostream>

using namespace std;

int main() {
  int sum = 0;
  
  int i = 1;
  int j = 1;
  int k;
  
  while(j <= 4000000) {
    if(j % 2 == 0) {
      sum += j;
    }
    
    k = j;
    j += i;
    i = k;
  }
  cout << sum << endl;
  
  return 0;
}
