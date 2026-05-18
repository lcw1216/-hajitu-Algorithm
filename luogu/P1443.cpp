#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> sp;
vector<vector<int>> sum={{1,2},{2,1},{-1,2},{-2,1},{1,-2},{2,-1},{-1,-2},{-2,-1}};
void bfs(vector<int> st){
    int x = st[0],y = st[1];
    sp[x][y]=0;
    deque<vector<int>> dq;
    dq.push_back(st);
    while(!dq.empty()){
        x = dq.front()[0],y = dq.front()[1];dq.pop_front();
        for(int i=0;i<8;i++){
            int xx = x+sum[i][0],yy = y+sum[i][1];
            if(xx<0||xx>=n||yy<0||yy>=m||sp[x][y]+1>=sp[xx][yy])continue;
            sp[xx][yy]=sp[x][y]+1;dq.push_back({xx,yy});
        }
    }
    return ;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    sp.resize(n,vector<int>(m,INT_MAX));
    vector<int> st(2);cin>>st[0]>>st[1];
    st[0]--;st[1]--;
    bfs(st);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            if(sp[i][j]!=INT_MAX) cout<<sp[i][j]<<' ';
            else cout<<-1<<' ';
        cout<<"\n";
    }
    return 0;
}