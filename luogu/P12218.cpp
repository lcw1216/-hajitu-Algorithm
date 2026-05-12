#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;cin>>n;
    vector<ll> nums(2*n);
    for(ll i=0;i<2*n;i++)cin>>nums[i];
    sort(nums.begin(),nums.end());
    ll ans = 0;
    for(ll i=0;i<n;i++){
        ans+=(nums[i]*nums[2*n-i-1]);
    }
    cout<<ans<<endl;
    return 0;
}