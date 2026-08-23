#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n,m,q;
vector<vector<pair<int,int>>> gp;
vector<int> dis;
void dij(){
    dis.assign(n+1,INT_MAX);
    dis[1] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> que;
    que.emplace(0,1);
    while(!que.empty()){
        auto [d,x] = que.top();que.pop();
        if(dis[x]==d){
            for(const auto& [y,v]:gp[x]){
                int newdis = d+v;
                if(newdis<dis[y]){
                    dis[y] = newdis;
                    que.emplace(newdis,y);
                }
            }
        }
    }
}
void solve(){
    cin>>n>>m>>q;
    gp.resize(n+1);
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        gp[u].push_back({v,w});
        gp[v].push_back({u,w});
    }
    dij();
    ll res = 0;
    while(q--){
        int a;cin>>a;
        res=dis[a];
        cout<<res<<endl;
    }
    
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