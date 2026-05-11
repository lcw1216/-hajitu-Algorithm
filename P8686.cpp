#include<bits/stdc++.h>
using namespace std;
vector<int> ms(1e6+10);
int find(int x){
    int t = x;
    while(ms[t]!=t)t=ms[t];
    while(ms[x]!=x){
        int n = ms[x];
        ms[x] = t;
        x = n;
    }
    return x;
}//路径压缩
int main(){
    int N;cin>>N;
    for(int i=0;i<1e6+10;i++)ms[i]=i;
    while(N--){
        int c;cin>>c;
        if(ms[c]!=c) c = find(c);
        ms[c] = find(c+1);
        cout<<c<<' ';
    }
    return 0;
}