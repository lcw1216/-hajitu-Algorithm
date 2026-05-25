#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ct_1(ll m){
    ll ct = 0;
    while(m>0){
        if(m%2==1)ct++;
        m/=2;
    }
    return ct;
}
int main(){
    ll k,n,m;cin>>k>>n>>m;
    m--;
    ll ans = ct_1(m);
    ans = ans%k;
    cout<<ans<<endl;
    return 0;
}