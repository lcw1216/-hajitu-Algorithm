#include<bits/stdc++.h>
using namespace std;
vector<int> to_lens(const vector<vector<int>>& gp,int st){
    int n = gp.size()-1;
    vector<int> lens(n+1,-1);lens[st]=1;
    queue<int> qe;qe.push(st);
    while(!qe.empty()){
        int x = qe.front();qe.pop();
        for(int i=0;i<(int)gp[x].size();i++){
            if(lens[gp[x][i]]==-1){
                lens[gp[x][i]]=lens[x]+1;
                qe.push(gp[x][i]);
            }
        }
    }
    return lens;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;cin>>n;
    vector<vector<int>> gp(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        gp[a].push_back(b);
        gp[b].push_back(a);
    }
    vector<int> mid = to_lens(gp,1);
    int maxm = 0,maxp;
    for(int i=1;i<=n;i++)maxm=max(maxm,mid[i]);
    for(int i=1;i<=n;i++)if(mid[i]==maxm){maxp=i;break;}
    vector<int> res = to_lens(gp,maxp);
    for(int i=1;i<=n;i++)maxm = max(maxm,res[i]);
    cout<<maxm<<endl;
    return 0;
}