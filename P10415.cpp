#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll x,ll y){
    while(y){
        ll t = y;
        y = x%y;
        x = t;
    }
    return x;
}
int main(){
    ll w,h;cin>>w>>h;
    ll mx = gcd(w,h);
    // cout<<mx<<endl;
    if(mx==1){cout<<0<<endl;return 0;}
    ll tar = (w/mx)*(h/mx);
    ll tmp = 1;
    if(mx==2||mx==3)tmp=mx;
    else {
        for(ll i=2;i*i<=mx;i++){
            if(mx%i==0){tmp = i;break;}
        }
    }
    if(tmp==1)tmp = mx;
    // cout<<tmp<<endl;
    ll res = tar*(mx/tmp)*(mx/tmp);
    cout<<res<<endl;
    return 0;
}