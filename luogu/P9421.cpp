#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)mp[nums[i]]++;
    int o=0,t=0;
    for(const auto&pair:mp){
        if(pair.second==1)o++;
        else if(pair.second>2)t+=(pair.second-2);
    }
    int ans = 0;
    if(t>=o)ans = t;
    else ans = t+(o-t)/2;
    cout<<ans<<endl;
    return 0;
}