/* 
 * Find the largest prime factor of 600851475143
 * 最大素因数を求める
 * Auther: takuzoo3868
 * Last Modified: 29/Apr/2017
 */

#include<iostream>

using namespace std;

int main() {
  long long num = 600851475143;
  long long factors = 2;
  long long primeFactors;
  
  while (factors *factors < 600851475143){
    while (num % factors == 0){
      num = num / factors;
      primeFactors = factors;
    }
    factors += 1;
  }
  cout << primeFactors << endl;
  
  return 0;
}

