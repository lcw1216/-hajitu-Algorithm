#include<bits/stdc++.h>
using namespace std;
//找到有多少个联通图，然后这个数-1就是需要的路的数量
int main(){
    int n,m;
    while(cin>>n>>m){
    vector<vector<int>> mp(n+1);
    while(m--){
        int a,b;cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    vector<bool> bl(n+1,false);
    int cnt = 0;
    for(int i=1;i<=n;i++){
        deque<int> dq;
        if(!bl[i]){
            cnt++;
            dq.push_back(i);
            bl[i]=true;
        }
        while(!dq.empty()){
            int x = dq.front();dq.pop_front();
            for(int j=0;j<mp[x].size();j++){
                if(!bl[mp[x][j]]){
                    bl[mp[x][j]]=true;
                    dq.push_back(mp[x][j]);
                }
            }
        }
    }
    int ans = cnt-1;
    cout<<ans<<endl;
}
    // for(int i=0;i<=n;i++)
    //     if(bl[i])cout<<1<<' ';
    //     else cout<<0<<' ';
    // cout<<cnt<<endl;
    
    return 0;
}