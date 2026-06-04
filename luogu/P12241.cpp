#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//风味接雨水
int main(){
    ll n;cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++)cin>>a[i];
    //单调栈，单调上升，查找上一个小于当前值的下标,左右维护
    stack<ll> lst,rst;
    vector<ll> ldp(n),rdp(n);
    ll pos;
    //找到上一个小于当前值的下标
    for(ll i=0;i<n;i++){
        while(!lst.empty()&&a[lst.top()]>=a[i])lst.pop();
        if(lst.empty())pos = 0;else pos = lst.top()+1;
        ldp[i] = pos;
        lst.push(i);
    }
    for(ll i=n-1;i>=0;i--){
        while(!rst.empty()&&a[rst.top()]>=a[i])rst.pop();
        if(rst.empty())pos = n-1;else pos = rst.top()-1;
        rdp[i] = pos;
        rst.push(i);
    }
    ll ans = 0;
    for(ll i=0;i<n;i++){
        ans = max(ans,(rdp[i]-ldp[i]+1)*a[i]);
    }
    cout<<ans;
    return 0;
}