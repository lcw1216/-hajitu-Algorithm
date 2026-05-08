#include<bits/stdc++.h>
using namespace std;
//可以将区块使用1分割，对于同一区块使用最大值加入次数
//用1分割不可行，应当遇到比前一个数小的数则进行局部结算
int main(){
    int n;cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    nums.push_back(1);
    int ans = 0;
    for(int i=1;i<=n;i++){
        if((nums[i]<nums[i-1])){ans+=(nums[i-1]-nums[i]);}
    }
    cout<<ans<<endl;
    return 0;
}