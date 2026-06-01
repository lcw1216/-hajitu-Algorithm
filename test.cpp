#include<bits/stdc++.h>
using namespace std;
bool check(vector<int> nums,int m,int x){
    //检查是否能在m次以内将最小值缩减到x
    //大概方法是，将所有大于x的木棒，剪切nums[i]/x次
    //如果nums[u]%==0就nums[i]/x-1次
    int len = nums.size(),ct = 0;
    for(int i=0;i<len;i++){
        if(nums[i]<=x)continue;
        else {
            ct+=(nums[i]/x);
            if(nums[i]%x==0)ct--;
        }
    }
    if(ct<=m)return true;
    return false;
}
int bs(vector<int> nums,int m,int maxval){
    int l = 1,r = maxval,ans = maxval;
    while(l<r){
        int mid = (l+r)/2;
        if(check(nums,m,mid)){ans = mid;r = mid;}
        else l = mid+1;
    }
    return ans;
}
int main(){
    int n,m;cin>>n>>m;
    vector<int> nums(n);
    int maxval = 0;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        maxval = max(nums[i],maxval);
    }
    int ans = bs(nums,m,maxval);
    cout<<ans<<endl;
    return 0;
}