#include<bits/stdc++.h>
using namespace std;
 
int e[500000] = {};
int w[500000] = {};
 
int main(){
  int n;
  string s;
 
  cin>> n >> s;
  for(int i = 1; i <= n; i++) {
    e[i] = e[i - 1];
    w[i] = w[i - 1];
    if(s[i - 1] == 'E') e[i]++;
    if(s[i - 1] == 'W') w[i]++;
  }
 
  int ans = 1145141919; //┌（┌ ＾o＾）┐ﾎﾓｫ
 
  for(int i = 1; i <= n; i++) {
    int tmp = w[i - 1] + e[n] - e[i];
    ans = min(ans, tmp);
  }
 
  cout<< ans <<endl;
  return 0;
}
