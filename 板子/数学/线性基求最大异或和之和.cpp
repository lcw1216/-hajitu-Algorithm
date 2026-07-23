#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//将一个整数列表分为两个集合使这两个集合的异或和的和最大，输出最大得分
vector<ll> b(61,0);
void insert(ll x){
    for(ll i=60;i>=0;i--){
        if(((x >> i)&1)==0)continue;
        if(b[i]==0){b[i]=x;return ;}
        x^=b[i];
    }
}
ll to_res(ll n,vector<ll> a){
    fill(b.begin(),b.end(),0);
    ll tol = 0;
    for(ll i=0;i<n;i++)tol^=a[i];
    ll mask = ((1LL << (60 + 1)) - 1)^tol;
    for(ll i=0;i<n;i++)insert(a[i] & mask);
    ll mx = 0;
    for(ll i=60;i>=0;i--){
        if((mx^b[i])>mx)mx^=b[i];
    }
    return tol+mx*2;

}
int main(){
    ll T;cin>>T;
    while(T--){
        ll n;cin>>n;
        vector<ll> a(n);
        for(ll i=0;i<n;i++)cin>>a[i];
        ll ans = to_res(n,a);
        cout<<ans<<endl;
    }
    return 0;
}