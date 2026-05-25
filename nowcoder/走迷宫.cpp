#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> sum = {{0,0,0,1},{0,0,1,0},{0,1,0,0},{1,0,0,0},{0,0,0,-1},{0,0,-1,0},{0,-1,0,0},{-1,0,0,0}};
int n;
vector<int> to_xy(int i,int j){
    i++;j++;
    vector<int> ans(4);
    ans[0] = ((i-1)%n)+1;
    ans[1] = ((j-1)%n)+1;
    ans[2] = ((j-1)/n)+1;
    ans[3] = ((i-1)/n)+1;
    return ans;
}
int main(){
    int T;cin>>T;
    while(T--){
        cin>>n;
        vector<vector<char>> mp(n*n,vector<char>(n*n));
        vector<int> a(4),e(4);
        vector<vector<vector<vector<bool>>>> bl(n+1,vector<vector<vector<bool>>>(n+1,vector<vector<bool>>(n+1,vector<bool>(n+1,true))));
        for(int i=0;i<n*n;i++) for(int j=0;j<n*n;j++) {
            cin>>mp[i][j];
            if(mp[i][j]=='S'){a=to_xy(i,j);bl[a[0]][a[1]][a[2]][a[3]]=false;}
            else if(mp[i][j]=='E'){e=to_xy(i,j);bl[e[0]][e[1]][e[2]][e[3]]=false;}
            else if(mp[i][j]=='#'){vector<int> t = to_xy(i,j);bl[t[0]][t[1]][t[2]][t[3]]=false;}
        }
        //mp check, fo check
        deque<vector<int>> dq;
        a.push_back(0);
        dq.push_back(a);
        int reslen = -1;
        while(!dq.empty()){
            vector<int> tp = dq.front();dq.pop_front();
            for(int i=0;i<8;i++){
                vector<int> tmp = tp;
                for(int j=0;j<4;j++)tmp[j]+=sum[i][j];
                bool out = false;
                for(int j=0;j<4;j++)if(tmp[j]<=0||tmp[j]>n){out=true;break;}
                if(out)continue;
                bool res = true;
                for(int j=0;j<4;j++)if(tmp[j]!=e[j])res=false;
                if(res){reslen=tp[4]+1;break;}
                if(bl[tmp[0]][tmp[1]][tmp[2]][tmp[3]]){
                    tmp[4]++;
                    bl[tmp[0]][tmp[1]][tmp[2]][tmp[3]]=false;
                    dq.push_back(tmp);
                }
            }
            if(reslen!=-1)break;
        }
        cout<<reslen<<endl;
    }
    return 0;
}