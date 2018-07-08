#include <iostream>
using namespace std;
int N;
int ans;

int main(){
  cin >> N;
  if(N%2==0){
    ans = N;
  } else {
    ans = N*2;
  }
  cout << ans << endl;
  return 0;
}
