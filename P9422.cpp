#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,m;cin>>n>>m;
    vector<ll> a(n),b(m);
    for(ll i=0;i<n;i++)cin>>a[i];
    for(ll i=0;i<m;i++)cin>>b[i];
    ll ap=0,bp=0,la=0,lb=0,ta=a[0],tb=b[0];
    ll ans = 0;
    while(ap<n||bp<n){
        if(ta<tb){ap++;ta+=a[ap];}
        else if(ta>tb){bp++;tb+=b[bp];}
        else {
            ans += ((ap-la)+(bp-lb));
            ap++; bp++;
            ta = a[ap]; tb = b[bp];
            la = ap; lb = bp;
        }
    }
    cout<<ans<<endl;
    return 0;
}