#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    sort(nums.begin(),nums.end());
    int l=0,r=1;
    int ans = 0;
    for(int l=0;l<n/2;l++){
        while(r<n&&nums[r]<nums[l]*2)r++;
        if(r==n)break;
        ans++;
        r++;
    }
    cout<<ans<<endl;
    return 0;
}