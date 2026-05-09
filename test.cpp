#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
//我们用队列进行bfs，把所有联通的点打上一个遇到的这个联通图的点的值
//然后使用哈希图统计，每个联通图特有值出现的次数，当然你直接用数组也可以，范围不大
//然后将所有的点打上这个它所在的联通图的点的数量，
//当两个连续的点处于一个联通图中时，将第一个点与最大值进行比较
//当两个连续的点出狱不同的联通图中时，将两个点的所在联通图点数量总和相加与最大值比较
//最后对末尾的一个点进行比较处理，得到最终最大值，输出
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
    //不会使用断点的代价
    return 0;
}
// 这道题好好玩
