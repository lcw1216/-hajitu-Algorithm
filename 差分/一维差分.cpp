#include<bits/stdc++.h>
using namespace std;
int main(){
    int len,t;
    cin>>len>>t;
    vector<int> nums(len);
    for(int i=0;i<len;i++)cin>>nums[i];
    vector<int> diff(len+2,0);
    while(t--){
        int l,r,c;
        cin>>l>>r>>c;
        diff[l]+=c;
        diff[r+1]-=c;
    }
    for(int i=1;i<=len;i++){
        diff[i]+=diff[i-1];
        nums[i-1]+=diff[i];
    }
    for(int i=0;i<len;i++)cout<<nums[i]<<endl;
    return 0;
}