#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    ll n;cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++)cin>>a[i];
    if(n<3){cout<<0<<endl;return;}
    vector<ll> l(n),r(n);
    for(ll i=0;i<n;i++){l[i] = a[i];r[i] = a[i];}
    l[1] = max(0LL,l[1]-l[0]);r[n-2] = max(0LL,r[n-2]-r[n-1]);
    for(ll i=2;i<n;i++)l[i] = max(0LL,l[i]-l[i-1]-l[i-2]);
    for(ll i=n-3;i>=0;i--)r[i] = max(0LL,r[i]-r[i+1]-r[i+2]);
    for(ll i=1;i<n;i++) l[i] = l[i]+l[i-1];
    for(ll i=n-2;i>=0;i--) r[i] = r[i]+r[i+1];
    ll minval = min(r[2],l[n-3]);
    for(ll i=1;i<n-2;i++){
        minval = min(minval,l[i-1]+r[i+2]);
    }
    cout<<minval<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    //cin >> t;
    while (t--){
        solve();
    }
    return 0;
}