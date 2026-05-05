#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;cin>>n>>k;
    int res = -1;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    int tar = 0;
    for(int i=0;i<k;i++)tar = max(nums[i],tar);
    for(int i=k;i<n;i++)if(nums[i]>tar){res = nums[i];break;}
    if(res==-1)res = nums.back();
    cout<<res<<endl;
    return 0;
}