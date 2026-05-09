#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,p,q;
    cin>>n>>m>>p>>q;
    vector<vector<int>> np(n+1),mq(m+1);
    while(p--){
        int a,b;cin>>a>>b;
        if(a==b)continue;
        np[a].push_back(b);
        np[b].push_back(a);
    }
    while(q--){
        int a,b;cin>>a>>b;
        if(a==b)continue;
        a*=-1;b*=-1;
        mq[a].push_back(b);
        mq[b].push_back(a);
    }
    int ns=0,ms=0;
    deque<int> dq;
    vector<bool> bl(n+1,false);
    dq.push_back(1);bl[1]=true;
    while(!dq.empty()){
        int x = dq.front();dq.pop_front();
        for(int i=0;i<np[x].size();i++){
            if(!bl[np[x][i]]){
                bl[np[x][i]]=true;
                dq.push_back(np[x][i]);
            }
        }
    }
    for(int i=1;i<=n;i++)if(bl[i])ns++;
    vector<bool> bll(m+1,false);
    dq.push_back(1);bll[1]=true;
    while(!dq.empty()){
        int x = dq.front();dq.pop_front();
        for(int i=0;i<mq[x].size();i++){
            if(!bll[mq[x][i]]){
                bll[mq[x][i]]=true;
                dq.push_back(mq[x][i]);
            }
        }
    }
    
    // for(int i=1;i<=n;i++){
    //     cout<<i<<' ';
    //     for(int j=0;j<np[i].size();j++)cout<<np[i][j]<<' ';
    //     cout<<endl;
    // }
    // for(int i=1;i<=m;i++){
    //     cout<<i<<' ';
    //     for(int j=0;j<mq[i].size();j++)cout<<mq[i][j]<<' ';
    //     cout<<endl;
    // }
    for(int i=1;i<=m;i++)if(bll[i])ms++;
    // cout<<ns<<' '<<ms<<endl;
    int ans = min(ns,ms);
    cout<<ans<<endl;
    return 0;
}