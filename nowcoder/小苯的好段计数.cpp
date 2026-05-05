#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++)cin>>nums[i];
        stack<int> lt,rt;
        vector<vector<int>> lr(n,vector<int>(2));
        for(int i=0;i<n;i++){
            while(!lt.empty()&&nums[lt.top()]<nums[i])lt.pop();
            if(!lt.empty())lr[i][0]=lt.top()+1;else lr[i][0]=0;
            lt.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!rt.empty()&&nums[rt.top()]<nums[i])rt.pop();
            if(!rt.empty())lr[i][1]=rt.top()-1;else lr[i][1]=n-1;
            rt.push(i);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(lr[i][1]-lr[i][0]+1>=nums[i])ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}