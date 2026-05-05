#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
typedef long long ll;
int main(){
    ll n = 4052;
    ll mod_s = (MOD+1)/6;
    ll res = (n*(n-1))%MOD;
    res = res*(n-2)%MOD;
    res = res*2*mod_s%MOD;
    cout<<mod_s<<endl;
    cout<<res<<endl;
    return 0;    
}