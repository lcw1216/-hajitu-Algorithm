#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXI = 1e5;
int q;
map<int,int> mp{{1,0}};
map<int,int> cnt = {{0,MAXI+1}};
void add(int x,int v){
    cnt[x]+=v;
}
void Remove(int x,int v){
    auto it = cnt.find(x);
    if(!(it->second-=v))cnt.erase(it);
}
auto Split(int x){
    auto it = mp.lower_bound(x);
    if(it->first==x)return it;
    return mp.emplace_hint(it,x,prev(it)->second);
}
void Modify(int l,int r,int x){
    r++;
    auto itr = Split(r);
    auto itl = Split(l);
    for(auto it = itl;it!=itr;it = mp.erase(it)){
        Remove(it->second,next(it)->first - it->first);
    }
    mp.emplace_hint(itr,l,x);
    add(x,r-l);
}
void solve(){
    int q;cin>>q;
    while(q--){
        int l,r,x;cin>>l>>r>>x;
        Modify(l,r,x);
        cout<<cnt.size()<<endl;
    }
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