#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int (i)=a;(i)<=(b);++(i))

const int maxn =1e4 + 10;

long long a[200005];
long long l[200005],r[200005];
int main() {

  long long n;
  cin>>n;
  a[0] = 0;

  FOR(i,1,n){
    cin >> a[i];
    a[i]+=a[i-1];
  }

  int l=1,r=3;
  long long ans = 1e18;
  FOR(mid,2,n-2){
    while(l<mid&&abs(a[mid]-a[l]-a[l]) >= abs(a[mid]-a[l+1]-a[l+1])) l++;
    while(r<n&&abs(a[n]-a[r]-(a[r]-a[mid])) >= abs(a[n]-a[r+1]-(a[r+1]-a[mid]))) r++;

    long long MAX = max(a[l],max(a[mid]-a[l],max(a[r]-a[mid],a[n]-a[r])));
    long long MIN = min(a[l],min(a[mid]-a[l],min(a[r]-a[mid],a[n]-a[r])));
    ans = min(ans,MAX-MIN); 
  }

  cout << ans << endl;
  return 0;
}
