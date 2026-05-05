#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> td_prefix_sum(vector<vector<int> > nums){
    int n = nums.size();
    vector<vector<int>> pre(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+nums[i-1][j-1];
    return pre;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> nums(n,vector<int>(n,1));
    vector<vector<int>> pre = td_prefix_sum(nums);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout<<pre[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}