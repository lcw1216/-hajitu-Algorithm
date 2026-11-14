#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e4+10;
//给定一个图，然后找出所有到剩余点距离最近的点
vector<vector<int>> g;
ll cnt[N],sum[N],dep[N];
ll mn,m,n;
void dfs1(int p,int fa){
    dep[p] = dep[fa]+1;
    cnt[p] = 1;
    for(int i=0;i<(int)g[p].size();i++){
        if(g[p][i]!=fa){dfs1(g[p][i],p);cnt[p]+=cnt[g[p][i]];}
    }
}
void dfs2(int p,int fa){
    for(int i=0;i<(int)g[p].size();i++)
        if(g[p][i]!=fa){
            sum[g[p][i]] = sum[p]-cnt[g[p][i]]+(n-cnt[g[p][i]]);
            mn = min(mn,sum[g[p][i]]);
            dfs2(g[p][i],p);
        }
}
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    map<int,map<int,int>> mp;
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        if(mp[u][v]==0){
            g[u].push_back(v);
            g[v].push_back(u);
            mp[u][v] = 1;mp[v][u] = 1;
        }
    }
    dep[0] = -1;
    dfs1(1,0);
    for(int i=1;i<=n;i++)sum[1]+=dep[i];
    mn = sum[1];
    dfs2(1,0);
    for(int i=1;i<=n;i++){
        if(sum[i]==mn)cout<<i<<' ';
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--){
        solve();
    }
    return 0;
}