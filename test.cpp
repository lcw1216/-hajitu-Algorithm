#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums(10);
    for(int i=0;i<10;i++)nums[i]=i;
    int n;cin>>n;
    auto it = lower_bound(nums.begin(),nums.end(),n);
    int up_count = nums.end()-it;
    cout<<up_count<<endl;
    return 0;
}