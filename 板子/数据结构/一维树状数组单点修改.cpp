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
//在树状数组上二分查找第k大的树
//只有对统计树状数组的出现频率才能二分，考虑到离散化，所有树状数组都可实现
int kth(int k){
    int idx = 0;
    int bm = 1;
    while((bm<<1)<=n)bm <<= 1;
    for(int st=bm;st;st>>=1){
        int nt = idx+st;
        if(nt<=n&&c[nt]<k){
            idx = nt;
            k -= c[nt];
        }
    }
    return idx+1;
}
int main(){
    cin>>n;
    c.resize(n+1,0);
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        add(k,1);
    }
    int q;cin>>q;
    int ans = kth(3);
    cout<<ans<<endl;
    return 0;
}