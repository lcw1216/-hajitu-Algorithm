#include <bits/stdc++.h>
using namespace std;
using ll = long long;
mt19937_64 myRand64(chrono::steady_clock::now().time_since_epoch().count());
void solve()
{
    int n,q;cin>>n>>q;
    int has[125001],pre[250001];
    for(int i=1;i<=125000;i++)has[i]=myRand64();
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        if(a>n/2)pre[i]=pre[i-1];
        else pre[i]=pre[i-1]+has[a];
    }
    for(int i=1;i<=125000;i++)has[i]+=has[i-1]+has[i];
    while(q--){
        int l,r;cin>>l>>r;l--;
        int len = r-l;
        if(!(len&1)&&pre[r]-pre[l]==has[len/2])cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}