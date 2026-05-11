#include<bits/stdc++.h>
using namespace std;
//二维并查集，
int N;
vector<int>sm;
vector<vector<int>>dr = {{0,1},{1,0},{-1,0},{0,-1}};
int find(int x){
    int rt = x;
    while(sm[rt]!=rt)rt=sm[rt];
    while(sm[x]!=x){
        int nt = sm[x];
        sm[x]=rt;
        x = nt;
    }
    return x;
}//不使用递归，直接使用while遍历两遍，找到根节点然后将所有点指向根节点
int main(){
    int M;cin>>N>>M;
    vector<vector<int>> mp(N,vector<int>(N,-1));
    sm.resize(N*N+10);
    for(int i=0;i<N*N+10;i++)sm[i]=i;
    int ans = 0;
    vector<int> smsize(N*N+10,1);
    while(M--){
        int c,x,y;cin>>c>>x>>y;x--;y--;
        mp[x][y]=c;
        for(int i=0;i<4;i++){
            int xx = x+dr[i][0],yy = y+dr[i][1];
            if(xx<0||xx>=N||yy<0||yy>=N||mp[xx][yy]!=c)continue;
            int pos = find(xx*N+yy);
            if(sm[x*N+y]==x*N+y){sm[x*N+y]=pos;smsize[pos]++;}//这里有个易错点，最多只能做到将目前点指向根节点，不能将其变成根节点
            else if(find(sm[x*N+y])!=pos){//目前点根节点不为自己且和相邻点不同
                ans--;//对于每一组需要合并情况，ans--
                int l = find(sm[x*N+y]);
                if(smsize[pos]>smsize[l]){sm[l]=pos;smsize[pos]+=smsize[l];}//小的指向大的
                else {sm[pos]=l;smsize[l]+=smsize[pos];}
            }//将小的组的根节点合并到大的组的根节点
        }
        if(sm[x*N+y]==x*N+y)ans++;//目前点孤立
        cout<<ans<<endl;
    }
    return 0;
}
//路径压缩，按大小合并（进阶用法）

//错误 1：int l = sm[x*N+y] 不一定是根
//错误 2：sm[pos] = sm[l] 仍在操作可能非根的对象