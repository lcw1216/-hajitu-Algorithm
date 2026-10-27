#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    ll n,k;cin>>n>>k;
    ll ans  = 0;
    for(ll l =1,r;l<=n;l = r+1){
        ll t = k/l;
        if(t>0)r = min(n,k/t);
        else r = n;
        ans += k*(r-l+1)-(r-l+1)*(l+r)/2*t;
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--){
        solve();
    }
    return 0;
}