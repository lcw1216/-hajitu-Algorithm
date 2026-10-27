//题目https://www.nowcoder.com/practice/d53b2057ae8a4eaf8155447f6b709361?channelPut=tracker2
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
int n;
vector<int> w;
vector<vector<int>> g;
//对于构成回路，也就是首尾相连的情况下，只要找到回路里面最小的那个点的权值
//对于无法构成回路的独立点必须单独计费
//理论上来说 每一个回路的最小点的数量相乘应该就是方案数
vector<int> dfn,low,stk;
vector<bool> in;
int dfnCc = 1;
ll tot = 0;
ll fangan = 1;
void dfs(int x){
    dfn[x] = low[x] = dfnCc;
    dfnCc++;
    stk.push_back(x);
    in[x] = true;
    for(const auto& y:g[x]){
        if(in[y]){
            low[x] = min(low[x],dfn[y]);
            continue;
        }
        if(!dfn[y]){
            dfs(y);
            low[x] = min(low[x],low[y]);
        }
    }
    int mini = INT_MAX;
    int cnt = 0;
    if(dfn[x]==low[x]){
        int z = 0;
        while(z!=x){
            z = stk.back();stk.pop_back();
            in[z] = false;
            if(w[z]<mini){mini = w[z];cnt = 1;}
            else if(w[z]==mini)cnt++;
        }
        fangan = fangan*cnt%MOD;
        tot+=mini;
    }
}
void solve(){
    cin>>n;
    w.resize(n+1);
    g.resize(n+1);
    dfn.resize(n+1);
    low.resize(n+1);
    in.resize(n+1);
    for(int i=1;i<=n;i++)cin>>w[i];
    int m;cin>>m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])dfs(i);
    }
    cout<<tot<<' '<<fangan;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--){
        solve();
    }
    return 0;
}