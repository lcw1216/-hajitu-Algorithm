#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
//注意到2023由7*17*17组成
//求1到2023的2023次方中有多少个整数与2023互质
ll ct_pw(ll x,ll y){
    ll ans = 1;
    while(y>0){
        if(y%2==1)ans=ans*x%MOD;
        x=x*x%MOD;
        y/=2;
    }
    return ans;
}
int main(){
    ll t,a,b,c;
    t = ct_pw(2023,2023);
    a = ct_pw(7,2022)*ct_pw(289,2023)%MOD;
    b = ct_pw(17,2022)*ct_pw(119,2023)%MOD;
    c = ct_pw(119,2022)*ct_pw(17,2023)%MOD;
    ll ans = (t-a-b+c)%MOD;
    cout<<ans<<endl;
    return 0;
}