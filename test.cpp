#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
//二维差分相邻边求和
struct Node{
    ll x,y,val;
};
bool st_w(Node x,Node y){
    return x.val<y.val; 
}
vector<vector<ll>> pre;
ll n;
ll to_val(ll i,ll j){
    ll tol = 0;
    ll l1 = 1,r1 = i,l2 = i,r2 = j-1;
    tol += pre[l2][r2]-pre[l1-1][r2]-pre[l2][r1-1]+pre[l1-1][r1-1];
    l1 = i+1;r1 = j;l2 = j;r2 = n;
    tol += pre[l2][r2]-pre[l1-1][r2]-pre[l2][r1-1]+pre[l1-1][r1-1];
    return tol;
}
void solve(){
    cin>>n;
    pre.resize(n+1,vector<ll>(n+1,0));;
    for(ll i=1;i<=n;i++)for(ll j=i;j<=n;j++){cin>>pre[i][j];}
    for(ll i=1;i<=n;i++)for(ll j=1;j<=n;j++) pre[i][j] = pre[i][j]+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];

    ll ans = 0;
    for(int i=2;i+1<n;i+=2)ans+=to_val(i,i+1);
    ans+=to_val(1,n);
    ll t = 0;
    for(int i=1;i<n;i+=2)t+=to_val(i,i+1);
    ans = min(t,ans);
    cout<<ans<<endl;
}
int main(){
    ll t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}