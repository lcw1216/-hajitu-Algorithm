#include<bits/stdc++.h>
using namespace std;
vector<int> prefix_sum(vector<int> nums){
    int n = nums.size();
    vector<int> pre(n+1,0);
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+nums[i-1];
    return pre;
}
int main(){
    vector<int> nums(10);
    for(int i=0;i<10;i++)nums[i]=i+1;
    vector<int> pre = prefix_sum(nums);
    for(int i=0;i<=10;i++)cout<<pre[i]<<endl;
    return 0;
}