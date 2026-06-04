#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    vector<ll> sss;
    vector<bool> v(5e4,true);
    for(ll i=2;i<5e4;i++){
        if(v[i]){
            sss.push_back(i);
            if(i*i>=5e4)continue;
            for(ll j=i*i;j<5e4;j+=i)v[j]=false;
        }
    }
    ll n,len=sss.size();cin>>n;
    for(ll i=0;i<len;i++){
        if(n%sss[i]==0){
            cout<<n/sss[i]<<endl;
            break;
        }
    }
    return 0;
}