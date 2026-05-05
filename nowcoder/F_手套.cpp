#include<bits/stdc++.h>
using namespace std;
int to_res(vector<int> nums,vector<int> mums){
    int n = nums.size(),m = mums.size();
    vector<vector<int>> md(m);
    for(int i=0;i<m;i++){
        auto it = lower_bound(nums.begin(),nums.end(),mums[i]);
        int pos = it - nums.begin();
        int l = max(pos-1,0),r = min(pos,n-1);
        while(l>=0||r<n){
            int ipt = INT_MAX;
            if(l>=0){ipt = min(ipt,abs(mums[i]-nums[l]));l--;}
            if(r<n){ ipt = min(ipt,abs(mums[i]-nums[r]));r++;}
            md[i].push_back(ipt);
            if(md[i].size()>=m)break;
        }
    }
    vector<bool> mp(m,true);
    int tol = 0;
    for(int i=0;i<m;i++){
        int min_val = INT_MAX;
        for(int j=0;j<m;j++)if(mp[j])min_val = min(min_val,md[i][j]);
        for(int j=0;j<m;j++)if(mp[j]&&min_val==md[i][j]){mp[j]=false;tol+=md[i][j];}
    }
    return tol;
}
int main(){
    int n,m;cin>>n>>m;
    vector<int> nums(n),mums(m);
    for(int i=0;i<n;i++)cin>>nums[i];
    for(int i=0;i<m;i++)cin>>mums[i];
    sort(nums.begin(),nums.end());
    sort(mums.begin(),mums.end());
    int res;
    if(n>m)res = to_res(nums,mums);
    else res = to_res(mums,nums);
    cout<<res<<endl;
    return 0;
}