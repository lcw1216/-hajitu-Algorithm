#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
typedef long long ll;
ll fp(ll d,ll z){
    ll ans = 1;
    while(z>0){
        if(z%2==1)ans=ans*d%mod;
        d=d*d%mod;
        z/=2;
    }
    return ans;
}
int main(){
    ll T;cin>>T;
    while(T--){
        ll n,k;cin>>n>>k;
        // ll ans = fast_m((1+k)*k/2,n)-fast_m((1+k)*k/2,n-1);
        ll ans = fp((fp(2, k) - 1 + mod) % mod, n);
        cout<<ans<<endl;
    }
    return 0;
}