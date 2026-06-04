#include<bits/stdc++.h>
using namespace std;
// bfs
int main(){
    int x,y,z;cin>>x>>y>>z;
    int k = 1;
    deque<vector<int>> bfs;
    bfs.push_back({x,y,z,k,0});
    int maxval = 0;
    while(!bfs.empty()){
        int xx = bfs.front()[0],
            yy = bfs.front()[1],
            zz = bfs.front()[2],
            kk = bfs.front()[3],
            vv = bfs.front()[4];
        maxval = max(maxval,vv);
            bfs.pop_front();
        if(xx>0)bfs.push_back({xx-1,yy,zz,max(0,kk-1),vv+kk});
        if(yy>0)bfs.push_back({xx,yy-1,zz,kk,vv+kk});
        if(zz>0)bfs.push_back({xx,yy,zz-1,min(2,k+1),vv+kk});
    }
    cout<<maxval<<endl;
    return 0;
}