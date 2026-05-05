#include<bits/stdc++.h>
using namespace std;
//类背包dp
int to_res(int n,int m,vector<int>an,vector<int>bn){
    vector<int> dp(m+1,0);
    for(int i=0;i<n;i++){
        int a = an[i],b = bn[i];
        vector<int> tp = dp;
        //rest
        for(int j=0;j<=min(b,m);j++)dp[0]=max(dp[0],dp[j]);
        for(int j=max(0,m-b);j>=1;j--)dp[j]=max(dp[j],dp[j+b]);
        // cout<<"rest  ";for(int j=0;j<=m;j++)cout<<dp[j]<<' ';cout<<endl;
        //study
        if(m-b>=0)for(int j=m-b;j>=0;j--)dp[j+b]=max(tp[j+b],tp[j]+a);
        // cout<<"study  ";for(int j=0;j<=m;j++)cout<<dp[j]<<' ';cout<<endl;
    }
    int ans = 0;for(int i=0;i<=m;i++)ans = max(ans,dp[i]);
    return ans;
}
int main(){
    int T;cin>>T;
    while(T--){
        int n,m;cin>>n>>m;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        cout<<to_res(n,m,a,b)<<endl;
    }
    return 0;
}