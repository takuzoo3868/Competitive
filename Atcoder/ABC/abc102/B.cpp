#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n;
  int a[100];

  cin>>n;
  for(int i=0;i<n;i++) cin>>a[i];
  sort(a,a+n);
  cout<<abs(a[0]-a[n-1])<<endl;
  return 0;
}
