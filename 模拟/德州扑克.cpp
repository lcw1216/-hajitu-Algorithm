#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
pair<int,int> to_p(string s){
    int sum = -1,pos = -1;
    switch(s[0]){
        case 'A': pos = 13;break;
        case 'J': pos = 10;break;
        case 'Q': pos = 11;break;
        case 'K': pos = 12;break;
        case 'T': pos = 9;break;
        default: break;
    }
    if(s[0]>'1'&&s[0]<='9')pos = (int)(s[0]-'0'-1);
    switch(s[1]){
        case 'C': sum = 1;break;
        case 'D': sum = 2;break;
        case 'H': sum = 3;break;
        case 'S': sum = 4;break;
    }
    return {pos,sum};
}
pair<int,ll> to_pos(vector<pair<int,int>> a){
    sort(a.begin(),a.end());
    bool s_c = true;
    for(int i=0;i<4;i++){if(a[i].second!=a[i+1].second)s_c=false;}
    vector<int> mins = {1,2,3,4,13};bool min_st = true;
    for(int i=0;i<5;i++)if(a[i].first!=mins[i])min_st=false;
    bool s_s = min_st;
    if(!s_s){s_s = true;for(int i=0;i<4;i++){if(a[i].first!=a[i+1].first-1)s_s=false;}}
    if(s_s)return {s_c?9:5,min_st?0:(ll)a[4].first};
    unordered_map<int,int> mp;
    for(int i=0;i<5;i++)mp[a[i].first]++;
    vector<pair<int,int>> g;
    for(const auto&pair:mp)g.push_back({pair.first,pair.second});
    sort(g.begin(),g.end(),[](pair<int,int>x,pair<int,int>y){
        if(x.second!=y.second)return x.second>y.second;
        return x.first>y.first;
    });
    ll key = 0;
    for(const auto&x:g)key = key*100+x.first;
    if(g[0].second==4)return {8,key};
    if(g[0].second==3&&g[1].second==2)return {7,key};
    if(s_c)return {6,key};
    if(g[0].second==3)return {4,key};
    if(g[0].second==2&&g[1].second==2)return {3,key};
    if(g[0].second==2)return {2,key};
    return {1,key};
}
int cmp_hand(vector<pair<int,int>> x,vector<pair<int,int>> y){
    pair<int,ll> a = to_pos(x),b = to_pos(y);
    if(a<b)return -1;
    if(a>b)return 1;
    return 0;
}
void solve(){
    vector<pair<int,int>> a,b;
    for(int i=0;i<5;i++){string s;cin>>s;a.push_back(to_p(s));}
    for(int i=0;i<5;i++){string s;cin>>s;b.push_back(to_p(s));}
    int res = cmp_hand(a,b);
    if(res>0)cout<<"1"<<endl;
    else if(res<0)cout<<"-1"<<endl;
    else cout<<"0"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        solve();
    }
    return 0;
}