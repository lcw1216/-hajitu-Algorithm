#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    unordered_map<int,int> mp;
    int mpf = 1,k = 0;
    for(int i=0;i<=10;i++){mp[mpf]=i;mpf*=2;}
    for(int i=0;i<n;i++)k+=mp[nums[i]];
    cout<<k/11+1<<endl;
    return 0;
}