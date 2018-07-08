#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

long long solve(vector<long long> v, int b){
  long long sum = 0;
  for(int i = 0; i < v.size(); i++){
    sum += abs(v[i] - b);
  }
  return sum;
}

int main(){
  int b;
  vector<long long> v;
  long long a, t, n;

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> t;
    v.push_back(t - i - 1); 
  }
  sort(v.begin(), v.end());
  b = v[n / 2];
  a = solve(v, b);
  cout << a << endl;
}
