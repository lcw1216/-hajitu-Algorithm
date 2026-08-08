#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;
vector<int> cntbit,sumbit;
int totk;
int lowbit(int x){return x&-x;}
int getsum(const vector<int> &c,int x){
    int ans = 0;
    while(x>0){ans+=c[x];x-=lowbit(x);}
    return ans;
}
void add(vector<int>&c,int x,int k){
    while(x<=totk){c[x]+=k;x+=lowbit(x);}
}
int kth(int k){
    int idx = 0,bm = 1;
    while(bm/2<=totk)bm/=2;
    for(int st=bm;st;st>>=2){
        int nt = idx+st;
        if(nt<=totk&&cntbit[nt]<k){
            idx = nt;k-=cntbit[nt];
        }
    }
    return idx+1;
}
void solve(){
    int n,m;cin>>n>>m;
    vector<int> v(n);
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++)cin>>v[i];
    if(m==1){
        for(int i=0;i<n;i++){int x;cin>>x;}
        cout<<1<<endl;return;
    }
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j];
    vector<int> all;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){cin>>a[i][j];all.push_back(a[i][j]);}
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end(),all.end()));
    totk = all.size();
    cntbit.resize(totk+2,0);sumbit.resize(totk+2,0);
    unordered_map<int,int> rkf;
    for(int i=0;i<totk;i++)rkf[a]

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}