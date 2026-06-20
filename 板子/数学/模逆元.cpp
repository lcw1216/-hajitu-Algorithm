#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;//注意！！！使用题目给的模逆元
//通过费马小定理计算模逆元（需要
//原理 a作为除数，模逆元等于a^(mod-2)%mod
//理由 计算 a 的 (mod-1) 次方，然后除以 mod，得到的余数一定等于 1。所以a的mod-2次方就是a作为除数的时的模逆元
ll fp(ll a,ll b,ll mod) {
    ll res = 1;
    while (b>0) {
        if (b%2==1) res=res*a%mod;   
        a=a*a%mod;                  
        b/=2;                    
    }
    return res;
}
int main(){
    ll a,b;
    cin>>a>>b;
    //b作为除数
    ll invb = fp(b,mod-2,mod);// invb就是模逆元
    //模逆元使用方法
    //(A / B) % MOD = (A % MOD) * inv(B) % MOD
    ll ans = (a%mod)*(invb)%mod;
    return 0;
}