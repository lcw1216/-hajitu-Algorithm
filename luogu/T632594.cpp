#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll res = -1;
vector<ll> cost,ks;
ll n,m,k;
void bfs(ll pos,ll ku,ll my,ll tm){
    res = max(ku,res);
    if(my+ku<=res||pos>=n||tm<=0)return;
    //bc
    if(cost[pos+1]<=my)bfs(pos+1,ku,my-cost[pos+1],tm);
    if(cost[pos+1]<my){
        bfs(pos+1,ku+min(my,ks[pos]),my-min(my,ks[pos])-cost[pos+1],tm-1);
    }
}
int main(){
    cin>>n>>m>>k;
    cost.resize(n);ks.resize(n);
    for(ll i=1;i<n;i++)cin>>cost[i];
    for(ll i=0;i<n;i++)cin>>ks[i];
    bfs(0,0,m,k);bfs(0,min(m,ks[0]),m-min(m,ks[0]),k-1);
    cout<<res<<endl;
    return 0;
}