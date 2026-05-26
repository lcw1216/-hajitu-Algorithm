#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> xsum = {{2,2},{2,-2},{-2,2},{-2,-2}};
vector<vector<int>> msum = {{1,2},{2,1},{1,-2},{2,-1},{-1,2},{-2,1},{-1,-2},{-2,-1}};
vector<vector<int>> bfs(int a,int b,int n,char sumway){
    vector<vector<int>> sum;
    if(sumway=='x')sum=xsum;else sum=msum;
    vector<vector<int>> ans(n+1,vector<int>(n+1,-1));
    ans[a][b]=0;
    queue<vector<int>> qe;qe.push({a,b});
    while(!qe.empty()){
        int x = qe.front()[0],y = qe.front()[1];qe.pop();
        for(int i=0;i<(int)sum.size();i++){
            int xx = x+sum[i][0],yy = y+sum[i][1];
            if(xx<0||xx>n||yy<0||yy>n||ans[xx][yy]!=-1)continue;
            ans[xx][yy]=ans[x][y]+1;
            qe.push({xx,yy});
        }
    }
    return ans;
}
int main(){
    int n,xx,xy,mx,my;cin>>n>>mx>>my>>xx>>xy;
    vector<vector<int>> xmp = bfs(xx,xy,n,'x');
    vector<vector<int>> mmp = bfs(mx,my,n,'m');
    int ans = INT_MAX;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(xmp[i][j]!=-1&&mmp[i][j]!=-1){
                ans = min(ans,xmp[i][j]+mmp[i][j]);
            }
        }
    }
    if(ans==INT_MAX)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}