#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n,k;cin>>n>>k;
    vector<int> a(n);
    vector<int> cnt(n+1);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    int pos = -1,ans = 0;
    for(int i=0;i<n;i++)if(a[i]>k){pos = i;break;}
    map<int,int> mp;
    for(int i=pos;i<n;i++){
        int x = a[pos];
        if(mp.find(x)!=mp.end())ans+=mp[x];
        else{
            int ct = 0;
            
        }
    }
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}