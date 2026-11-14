#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//构建可以计算前缀的树状数组
const ll MAXN = 2e6+10;
vector<ll> c(MAXN+1),b(MAXN+1);
ll lowbit(ll x){return x & -x;}
ll getsum(ll x,vector<ll>&c){
    ll ans = 0;
    while(x>0){
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
void add(ll x,ll k,vector<ll>&c){
    while(x<=MAXN){
        c[x]+=k;
        x+=lowbit(x);
    }
}
ll kth(ll k,vector<ll>&c){
    ll idx = 0;
    ll bm = 1;
    while((bm<<1)<=MAXN)bm <<= 1;
    for(ll st=bm;st;st>>=1){
        ll nt = idx+st;
        if(nt<=MAXN&&c[nt]<k){
            idx = nt;
            k -= c[nt];
        }
    }
    return idx+1;
}
ll query(ll l,ll r,vector<ll>&c){
    if(l>r) return 0;
    return getsum(r,c)-getsum(l-1,c);
}
//在树状数组上二分查找第k大的树
//只有对统计树状数组的出现频率才能二分，考虑到离散化，所有树状数组都可实现
//多测记得清空
int main(){
    int x;cin>>x;
    for(int i=1;i<=x;i++){
        add(i,1,c);
    }
    int ans = kth(3,c);
    cout<<ans<<endl;
    return 0;
}