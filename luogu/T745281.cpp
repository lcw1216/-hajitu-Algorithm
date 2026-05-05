#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,x,y;cin>>n>>m>>x>>y;
    vector<vector<int>>nums(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>nums[i][j];
        }
    }
    vector<int> ct(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(nums[i][j])ct[i]++;
        }
    }
    int tol = 0;
    for(int i=n-1;i>x-1;i--) tol+=ct[i];
    int l = tol+1,r = tol+ct[x-1];
    cout<<l<<' '<<r<<endl;
    return 0;
}