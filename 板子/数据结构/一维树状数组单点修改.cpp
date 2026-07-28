#include<bits/stdc++.h>
using namespace std;
//构建可以计算前缀的树状数组
vector<int> c;
int n;
int lowbit(int x){return x & -x;}
int getsum(int x){
    int ans = 0;
    while(x>0){
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
void add(int x,int k){
    while(x<=n){
        c[x]+=k;
        x+=lowbit(x);
    }
}
int main(){
    cin>>n;
    c.resize(n+1,0);
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        add(i,k);
    }
    int q;cin>>q;
    int ans = getsum(q);
    cout<<ans<<endl;
    return 0;
}