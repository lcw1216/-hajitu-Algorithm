#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
typedef long long ll;
int main(){
    ll n;cin>>n;
    string s;cin>>s;
    ll res = 1;
    ll j = n/2+n%2,o = n/2;
    ll jc = 0,oc = 0,tc = 0;
    for(ll i=0;i<n;i++){
        if(s[i]=='j')jc++;
        else if(s[i]=='o')oc++;
        else if(s[i]=='?')tc++;
    }
    if(j<jc||o<oc)res=0;
    else{
    for(ll i=j-jc+1;i<=j;i++)res=res*i%MOD;
    for(ll i=o-oc+1;i<=o;i++)res=res*i%MOD;
    for(ll i=1;i<=tc;i++)res=res*i%MOD;
}
    cout<<res<<endl;
    return 0;
}