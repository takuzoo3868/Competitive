#include<bits/stdc++.h>
using namespace std;

const int maxn=100005;
int pre[maxn],f[maxn+5];

int Find(int x) {
  if(pre[x]==x)
    return x;
  int ret=Find(pre[x]);
  f[x]=f[x]+f[pre[x]];
  return pre[x]=ret;
}

int main() {
  int n, m;
  bool flag=true;

  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)
    pre[i]=i;

  for(int i=1;i<=m;i++) {
    int l,r,d;
    scanf("%d%d%d",&l,&r,&d);
    if(flag) {
      if(Find(l)==Find(r)) {
        if(f[r]<=f[l]) {
          int p=f[l]-f[r];
          if(p!=d)
            flag=false;
        }
        else
          flag=false;
      }
      else {
        int k=Find(l);
        pre[k]=l;
        f[k]=-f[l];
        pre[l]=r;
        f[l]=d;
      }
    }
  }
  if(flag){
    cout<<"Yes"<<endl;
    return 0;
  } else {
    cout<<"No"<<endl;
    return 0;
  }
}
