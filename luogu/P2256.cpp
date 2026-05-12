#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main(){
    int N,M;cin>>N>>M;
    unordered_map<string,int> mp;
    vector<string> name(N);
    for(int i=0;i<N;i++){
        cin>>name[i];
        mp[name[i]]=i;
    }
    vector<vector<int>> v(N);
    while(M--){
        string l,r;cin>>l>>r;
        int x = mp[l],y = mp[r];
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vector<bool> bl(N,false);
    for(int i=0;i<N;i++){
        if(!bl[i]){
            bl[i]=true;
            int tp = i;
            deque<int> dq;
            dq.push_back(i);
            while(!dq.empty()){
                int x = dq.front();dq.pop_front();
                for(int j=0;j<v[x].size();j++){
                    if(!bl[v[x][j]]){
                        bl[v[x][j]]=true;
                        mp[name[v[x][j]]]=tp;
                        dq.push_back(v[x][j]);
                    }
                }
            }
        }
    }
    int K;cin>>K;
    while(K--){
        string a,b;cin>>a>>b;
        if(mp[a]==mp[b])cout<<"Yes."<<endl;
        else cout<<"No."<<endl;
    }
    return 0;
}