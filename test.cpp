#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n;cin>>n;
    vector<bool> lmx(n),rmn(n);
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int mx = 0,mn = n+1;
    for(int i=0;i<n;i++) { if(a[i]>mx) lmx[i] = true; mx = max(a[i],mx);}
    for(int i=n-1;i>=0;i--){ if(a[i]<mn) rmn[i] = true; mn = min(a[i],mn); }
    //每个区间必须要存在一个mx和一个mn
    vector<int> lp(n);
    int x = -1,y = -1;
    for(int i=0;i<n;i++){
        if(lmx[i])x = i;
        if(rmn[i])y = i;
        if(lmx[i]&&rmn[i])lp[i] = i;
        else if(lmx[i]) lp[i] = y;
        else if(rmn[i]) lp[i] = x;
        else lp[i] = lp[i-1];
    }
    // for(int i=0;i<n;i++)cout<<lp[i]<<' ';
    // cout<<endl;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(lp[i]!=-1)ans = ans+(lp[i]+1);
        // cout<<ans<<endl;
    }
    cout<<ans<<endl;
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