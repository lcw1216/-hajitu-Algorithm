#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    sort(nums.begin(),nums.end());
    auto lit = lower_bound(nums.begin(),nums.end(),nums[(n+1)/2-1]);
    auto rit = upper_bound(nums.begin(),nums.end(),nums[(n+1)/2-1]);
    int l = lit-nums.begin(),r = nums.end()-rit;
    int m = n - l - r;
    int res = n+1;
    if(l==0&&r==0){cout<<-1<<endl;return 0;}
    if(l>0)res = min(res,n-2*l);
    if(r>0)res = min(res,n-(2*r-1));
    res = min(m,res);
    cout<<res<<endl;
    return 0;
}