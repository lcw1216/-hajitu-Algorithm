//自己用的时候改一下，就是那个dij函数最重要
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
//dij找到s到x的最短路径和x到t的最短路径相加
int n;
vector<vector<int>> gp;
unordered_map<long long,long long> mp;
vector<long long> dis;
struct cmp{
        bool operator()(int x,int y){return dis[x]>dis[y];}
    };
long long to_sx(int st,int ed){
    vector<bool> vis(n+1,false);
    priority_queue<int,vector<int>,cmp> pq;
    pq.push(st);
    dis[st]=0;
    while(!pq.empty()){
        int x = pq.top();pq.pop();
        if(vis[x])continue;
        vis[x]=true;
        for(int i=0;i<(int)gp[x].size();i++){
            if(vis[gp[x][i]])continue;
            if(dis[x]+mp[x*1e5+gp[x][i]]<dis[gp[x][i]]){
                dis[gp[x][i]]=dis[x]+mp[x*1e5+gp[x][i]];
                pq.push(gp[x][i]);
            }
        }
    }
    return dis[ed];
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int m;cin>>n>>m;
    gp.resize(n+1);
    for(int i=0;i<m;i++){
        long long u,v,w;cin>>u>>v>>w;
        gp[u].push_back(v);
        gp[v].push_back(u);
        if(mp[u*1e5+v]!=0){
        mp[u*1e5+v]=min(w,mp[u*1e5+v]);
        mp[v*1e5+u]=min(w,mp[v*1e5+u]);
        }else {
            mp[u*1e5+v]=w;
            mp[v*1e5+u]=w;
        }
    }
    int s,x,t;cin>>s>>x>>t;
    dis.resize(n+1,1e16);
    long long l = to_sx(s,x);
    dis.assign(n+1,1e16);
    long long r = to_sx(x,t);
    cout<<l+r<<endl;
    return 0;
}