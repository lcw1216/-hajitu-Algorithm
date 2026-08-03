//一维树状数组板子
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+7;
int t1[MAXN], t2[MAXN], n;

int lowbit(int x) { return x & (-x); }

void add(int k, int v) {
  int v1 = k * v;
  while (k <= n) {
    t1[k] += v, t2[k] += v1;
    k += lowbit(k);
  }
}

int getsum(int *t, int k) {
  int ret = 0;
  while (k) {
    ret += t[k];
    k -= lowbit(k);
  }
  return ret;
}

void add1(int l, int r, int v) {
  add(l, v), add(r + 1, -v);  
}

long long getsum1(int l, int r) {
  return (r + 1ll) * getsum(t1, r) - 1ll * l * getsum(t1, l - 1) -
         (getsum(t2, r) - getsum(t2, l - 1));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    memset(t1,0,sizeof(t1));
    memset(t2,0,sizeof(t2));
    for(int i=1;i<=n;i++)add1(i,i,a[i]);
    int l,r,x;cin>>l>>r>>x;
    add1(l,r,x);
    long long ans = getsum1(l,r);
    cout<<ans<<endl;
}