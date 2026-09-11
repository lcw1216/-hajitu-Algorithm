#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string to_b(int x){
    string ans;
    while(x>0){
        ans.push_back((char)(x%2+'0'));
        x/=2;
    }
    return ans;
}
void solve(){
      int x,y;cin>>x>>y;
      if(x==0||y==0) {cout<<x+y<<' '<<0<<endl;return ;}
      int maxval = x+y;
      int ans = 0;
      while(maxval>(x^y)){
        int k = 1;
        int xt = x,yt = y;
        while(xt>0&&yt>0){
            int a = xt%2,b = yt&2;
            xt/=2;yt/=2;
            if(a==1&&b==1){
                x -= k;y -= k;
                ans += k;
                break;
            }
            k = k*2;
        }
      }
      cout<<maxval<<' '<<ans<<endl;
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