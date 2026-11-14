#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n;cin>>n;
    vector<vector<int>> a = {{},{1},{1,1}};
    for(int i=3;i<=n;i++){
        vector<int> b(i,1);
        for(int j=1;j<i-1;j++)b[j] = a[i-1][j]+a[i-1][j-1];
        a.push_back(b);
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<i;j++)cout<<a[i][j]<<' ';
    //     cout<<endl;
    // }
    //杨辉三角的点为C(i,n-1)//n是当前层数
    int t,c;cin>>t>>c;//这个逻辑仅用于求组合数
    c--;
    int ans = 1;
    t = min(c-1-t,t);
    cout<<t<<' '<<c+1-t<<' '<<c<<endl;
    for(int i=c-t+1;i<=c;i++)ans*=i;

    for(int i=1;i<=t;i++)ans/=i;
    cout<<ans<<endl;
    cout<<a[c+1][t]<<endl;
    //测试输入
    // 2 5 6
    // 15
    // 15
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--){
        solve();
    }
    return 0;
}