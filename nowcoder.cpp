#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    for(int i=0;i<n-1;i++){
        int x,y;cin>>x>>y;
    }
    int cntr = 0,cntl = 0;;
    for(int i=0;i<n;i++)if(s[i]=='R')cntr++;
    else cntl++;
    cout<<min(cntl,cntr)<<endl;
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