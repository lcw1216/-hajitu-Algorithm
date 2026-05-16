#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll T;cin>>T;
    while(T--){
        ll l,r;cin>>l>>r;
        if(r-2*l<0){cout<<0<<endl;continue;}
        ll top = r-2*l+1;
        ll ans = (1+top)*(top)/2;
        cout<<ans<<endl;
    }
    return 0;
}