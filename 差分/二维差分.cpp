#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> nums(m,vector<int>(n));
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) cin>>nums[i][j];            
    vector<vector<int>> diff(m+2,vector<int>(n+2,0));
    int t; cin>>t;
    while(t--){
        int x1,y1,x2,y2,c;
        cin>>x1>>y1>>x2>>y2>>c;
        diff[x1][y1]+=c;
        diff[x1][y2+1]-=c;
        diff[x2+1][y1]-=c;
        diff[x2+1][y2+1]+=c;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            diff[i][j]+=diff[i-1][j]+diff[i][j-1]-diff[i-1][j-1];
            nums[i-1][j-1]+=diff[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<nums[i][j];
        }
        cout<<endl;
    }
    return 0;
}