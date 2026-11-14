#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int MAXI = 1e6-2;
array<int,MAXI+1> fac;
array<int,MAXI+1> invFac;
ll n,m;
//求C上(n-2)下(m-1);
void init(){
    invFac[1] = 1;
    for(int i=2;i<=MAXI;i++)
        invFac[i] = (ll)(MOD-MOD/i)*invFac[MOD%i]%MOD;
        fac[0] = 1;
        invFac[0] = 1;
        for(int i=1;i<=MAXI;i++){
            fac[i] = (ll)fac[i-1]*i%MOD;
            invFac[i] = (ll)invFac[i-1]*invFac[i]%MOD;
        }
}
ll to_C(ll x,ll y){
    return (ll)fac[x]*invFac[x-y]%MOD*invFac[y]%MOD;
}
void solve(){
    cin>>n>>m;
    cout<<to_C(n-2,m-1)<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}