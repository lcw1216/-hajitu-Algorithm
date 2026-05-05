#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x,y,w;cin>>n>>x>>y>>w;
    vector<vector<int>> nums(n,vector<int>(2));
    int tol = 0;
    for(int i=0;i<n;i++)cin>>nums[i][0]>>nums[i][1];
    sort(nums.begin(),nums.end());
    int len = nums.size();
    deque<vector<int>>dq;
    for(int i=0;i<len;i++)dq.push_back({nums[i][0],nums[i][1]});
    int res = 0;
    bool first = true;
    while(dq.back()[1]>0){
        int lp = w;
        while(lp>0&&dq.back()[1]>0){
            lp-=min(lp,dq.front()[1]);
            dq.front()[1]-=min(lp,dq.front()[1]);
        }

    }
}//deque