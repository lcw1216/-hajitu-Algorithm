#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//前缀和加滑动窗口
const ll inf = 2e18;
int main(){
    int T;cin>>T;
    while(T--){
        ll n,k;cin>>n>>k;
        vector<ll> a(n);
        for(ll i=0;i<n;i++)cin>>a[i];
        sort(a.begin(),a.end());
        vector<ll> pre(n);
        for(ll i=0;i<n;i++)pre[i]=a[i];
        for(ll i=1;i<n;i++)pre[i]=pre[i]+pre[i-1];
        ll tol = pre[n-1];
        if(k==1||k==2){cout<<tol<<endl;continue;}
        ll l_l,r_l;
        if(k%2==1)l_l=(k-1)/2;else l_l=k/2-1;
        r_l=l_l;
        ll l_v = pre[l_l-1],sum = -inf;
        // cout<<l_v<<endl;
        if(k%2==1){
            for(ll r=l_l;r<n-r_l;r++){
                ll mid=a[r]*(k-1);
                ll r_v;r_v=pre[r+r_l]-pre[r];
                sum = max(sum,mid-r_v-l_v);
            }
        }else {
            for(ll r=l_l;r<n-r_l-1;r++){
                ll mid = (a[r]+a[r+1])*((k-2)/2);
                ll r_v = pre[r+1+r_l]-pre[r+1];
                sum = max(sum,mid-r_v-l_v);
                // cout<<sum<<endl;
            }
        }
        cout<<tol+sum<<endl;
    }
    return 0;
}
