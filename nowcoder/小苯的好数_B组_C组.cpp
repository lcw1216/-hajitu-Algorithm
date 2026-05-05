#include<bits/stdc++.h>
using namespace std;
bool check(int x){
    if(x%2==0)return true;
    if(x==1)return false;
    if((int)sqrt(x)*(int)(sqrt(x))==x)return true;
    return false;
}
int main(){
    int T;cin>>T;
    while(T--){
        int n,q;cin>>n>>q;
        vector<int> nums(n);
        for(int i=0;i<n;i++)cin>>nums[i];
        for(int i=0;i<n;i++)if(check(nums[i]))nums[i]=1;else nums[i]=0;
        vector<int> pre(n+1,0);
        for(int i=1;i<=n;i++)pre[i]=pre[i-1]+nums[i-1];
        while(q--){
            int l,r;cin>>l>>r;
            cout<<pre[r]-pre[l-1]<<endl;
        }
    }
    return 0;
}   