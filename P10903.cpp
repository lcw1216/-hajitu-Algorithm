#include<bits/stdc++.h>
using namespace std;
//常规处理之后用前缀和计算每个区间的1的数量，将总数加上这些数量
int main(){
    int n,m;cin>>n>>m;
    vector<int> nums(n+2,0);
    vector<vector<int>> mt(m,vector<int>(2));
    for(int i=0;i<m;i++)cin>>mt[i][0]>>mt[i][1];
    for(int i=0;i<m;i++){
        int l=mt[i][0],r=mt[i][1];
        nums[l]++;
        nums[r+1]--;
    }
    for(int i=1;i<=n;i++)nums[i]+=nums[i-1];
    vector<int> ps(n+2,0);
    for(int i=1;i<=n;i++)if(nums[i]==1)ps[i]=1;
    for(int i=1;i<=n;i++)ps[i]+=ps[i-1];
    int tol = 0;
    for(int i=1;i<=n;i++)if(nums[i]==0)tol++;
    for(int i=0;i<m;i++){
        int ans = tol + (ps[mt[i][1]]-ps[mt[i][0]-1]);
        cout<<ans<<endl;
    }
    return 0;
}