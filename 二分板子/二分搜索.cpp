#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18;
bool check(vector<int>& nums,int mid,int tar){
    return nums[mid]<=tar;
}
int bs(vector<int> nums,int tar){
    int l = 0, r = (int)nums.size() - 1;
    while(l<r){
        int mid = (l+r+1)/2;
        if(check(nums,mid,tar))l=mid;
        else r=mid-1;
    }
    return l;
}

bool check_ll(ll x){
    if(x==0)return true;
    return x<=INF/x;
}
ll bs_ll(ll l,ll r){
    while(l<r){
        ll mid = (l+r+1)/2;
        if(check_ll(mid))l=mid;
        else r=mid-1;
    }
    return l;
}

void solve(){
    vector<int> nums(10);
    for(int i=0;i<10;i++)nums[i]=i;
    cout<<bs(nums,5)<<"\n";
    cout<<bs_ll(0,INF)<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--){
        solve();
    }
    return 0;
}