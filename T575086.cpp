#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
ll to_res(ll x){
    ll ans = 1,a = 2;
    while(x>0){
        if(x%2==1)ans=ans*a%MOD;
        a=a*a%MOD;
        x/=2;
    }
    return ans;
}
int main(){
    ll T;cin>>T;
    while(T--){
        ll res;
        ll x,y;cin>>x>>y;
        res = (y+1)*to_res(x-y-1)%MOD;
        if(x<=y)res=1;
        cout<<res<<endl;
    }
    return 0;
}