#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int g(int n){return n^(n>>1);}
int rev_g(int g) {
  int n = 0;
  for (; g; g >>= 1) n ^= g;
  return n;
}
void solve(){
    int n;cin>>n;
    for(int i=0;i<n;i++)cout<<rev_g(g(i))<<endl;
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