#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD =  1e9+7;
//用0结尾的序列可以连接用1开头的序列和用0开头的序列
//用1结尾的序列可以连接用1开头的序列
void addi(ll& a,ll& b){
    a = (a+b)%MOD;
}
ll n;
string s;
vector<vector<ll>> dp;
//矩阵相乘
vector<vector<ll>> mul(const vector<vector<ll>>& a,const vector<vector<ll>>& b){
    vector<vector<ll>> res = {{1,0},{0,1}};
    for(ll i=0;i<2;i++)for(ll j=0;j<2;j++){
        ll cur = 0;
        for(ll k=0;k<2;k++)cur+=(ll)(a[i][k]*b[k][j]);
        res[i][j] = cur%MOD;
    }
    return res;
}
void solve(){
    ll n;cin>>n;
    string s;cin>>s;
    dp = {{1,0},{0,1}};
    for(const auto& c:s){
        if(c=='0')addi(dp[0][0],dp[0][0]);
        else{
            addi(dp[1][0],dp[1][0]);
            addi(dp[1][0],dp[0][0]);
            addi(dp[1][1],dp[1][1]);
        }
    }
    //快速幂
    vector<vector<ll>> res = {{1,0},{0,1}};
    while(n){
        if(n&1)res = mul(res,dp);
        dp = mul(dp,dp);
        n >>= 1;
    }
    cout<<(res[0][0]+res[1][0]+(ll)MOD-1)%MOD<<endl;

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