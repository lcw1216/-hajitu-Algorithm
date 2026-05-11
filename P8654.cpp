#include<bits/stdc++.h>
using namespace std;
vector<int> ms;
int find(int x){
    int t = x;
    while(ms[t]!=t)t=ms[t];
    while(ms[x]!=x){
        int r = ms[x];
        ms[x] = t;
        x = r;
    }
    return x;
}//路径压缩
int main(){
    int m,n,k;cin>>m>>n>>k;
    int ans = m*n;ms.resize(ans);
    for(int i=0;i<ans;i++)ms[i]=i;
    vector<int> mssize(m*n+10,1);
    while(k--){
        int a,b;cin>>a>>b;
        if(find(a)==find(b))continue;
        if(ms[a]==a&&ms[b]==b){
            ms[b]=a;
            mssize[a]++;
        }else if(ms[a]!=a&&ms[b]==b){
            ms[b] = find(a);
            mssize[find(b)]++;
        }else if(ms[a]==a&&ms[b]!=b){
            ms[a] = find(b);
            mssize[find(a)]++;
        }else{
            if(mssize[find(a)]>mssize[find(b)]){
                ms[find(a)]=find(b);
                mssize[find(b)]+=mssize[find(a)];
            }
            else {
                ms[find(b)]=ms[find(a)];
                mssize[find(a)]+=mssize[find(b)];
            }
        }
        ans--;
    }
    cout<<ans<<endl;
    return 0;
}