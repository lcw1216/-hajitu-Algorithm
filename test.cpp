#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main(){
    int N;cin>>N;
    vector<int> a(N+1);
    for(int i=1;i<=N;i++)cin>>a[i];
    vector<int> b(N+1,0);
    for(int i=1;i<=N;i++){
        int tp = 0;
        if(b[i]==0)tp=i;
            else continue;
        deque<int>dq;
        dq.push_back(i);
        while(!dq.empty()){
            int x = dq.front();dq.pop_front();
            if(b[a[x]]==tp)break;
            b[a[x]] = tp;
            dq.push_back(a[x]);
        }
    }
    unordered_map<int,int> mp;
    for(int i=1;i<=N;i++) mp[b[i]]++;
    vector<int> t(N+1,0);
    for(int i=1;i<=N;i++)t[i] = mp[b[i]];
    int max_val = t[0];
    for(int i=1;i<N;i++){
        if(b[i]!=b[i+1]) max_val = max(max_val,t[i]+t[i+1]);
        else if(b[i]==b[i+1]) max_val = max(max_val,t[i]);
    }
    max_val = max(max_val,t[N]);
    cout<<max_val<<endl;
    // for(int i=1;i<=N;i++)cout<<a[i]<<' ';
    // cout<<endl;
    // for(int i=1;i<=N;i++)cout<<b[i]<<' ';
    return 0;
}
//链接 http://47.121.118.174/p/608
// 硬要说的话是我用的是数据结构的队列，但是应该是更高级的并查集之类
// 但是管他这的那的，反正好玩就完了