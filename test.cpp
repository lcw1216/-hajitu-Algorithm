#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
//转数字
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
//根据等级分别计算字典序
ll to_val(int lv,vector<pair<int,int>> a){
    sort(a.begin(),a.end());
    unordered_map<int,int> mp;
    for(int i=0;i<5;i++)mp[a[i].first]++;
    switch(lv){
        case 9: {if(a[0].first==1&&a.back().first==13)return 0; return a.back().first;}
        case 8: {
            ll x = -1,y = -1;
            for(const auto&pair:mp)if(pair.second==4)x = pair.first;else y = pair.first;
            return x*100+y;
        }
        case 7: {
            ll x = -1,y = -1;
            for(const auto&pair:mp)if(pair.second==3)x = pair.first;else y = pair.first;
            return x*100+y;
        }
        case 6: {
            reverse(a.begin(),a.end());
            ll ans = 0;
            for(int i=0;i<5;i++)ans = ans*100+a[i].first;
            return ans;
        }
        case 5: {if(a[0].first==1&&a.back().first==13)return 0;return a.back().first;}
        case 4: {
            ll x;vector<ll> r;
            for(const auto&pair:mp)if(pair.second==3)x = pair.first;else r.push_back(pair.first);
            return x*10000+max(r[0],r[1])*100+min(r[0],r[1]);
        }
        case 3: {
            ll x;vector<ll> l;
            for(const auto&pair:mp)if(pair.second==2)l.push_back(pair.first);else x = pair.first;
            return max(l[0],l[1])*10000+min(l[0],l[1])*100+x;
        }
        case 2:{
            ll x;vector<ll> r;
            for(const auto&pair:mp)if(pair.second==2)x = pair.first;else r.push_back(pair.first);
            sort(r.begin(),r.end());reverse(r.begin(),r.end());
            return x*1000000+r[0]*10000+r[1]*100+r[2];
        }
        case 1:{
            reverse(a.begin(),a.end());
            ll ans = 0;
            for(int i=0;i<5;i++)ans=ans*100+a[i].first;
            return ans;
        }
        default: break;
    }
    return -1;
}
//最优排位(判断等级)
pair<int,ll> to_pos(vector<pair<int,int>> a){
    sort(a.begin(),a.end());
    //同花
    bool s_c = true,s_s = true;
    for(int i=0;i<4;i++){if(a[i].second!=a[i+1].second)s_c=false;}
    //特判
    vector<int>mins = {1,2,3,4,13};bool min_st = true;
    for(int i=0;i<5;i++)if(a[i].first!=mins[i])min_st=false;
    if(min_st){if(s_c)return {9,to_val(9,a)};else return {5,to_val(5,a)};}
    for(int i=0;i<4;i++){if(a[i].first!=a[i+1].first-1)s_s=false;}
    if(s_c&&s_s)return {9,to_val(9,a)};
    int max_s = 0;
    unordered_map<int,int> mp;
    for(int i=0;i<5;i++)mp[a[i].first]++;
    bool san = false,two = false,tt=false;
    for(const auto&pair:mp){
        max_s = max(max_s,pair.second);
        if(pair.second==3)san = true;
        if(two&&pair.second==2)tt = true;
        if(pair.second==2&&!two)two = true;
    }
    if(max_s==4)return {8,to_val(8,a)};
    if(san&&two)return {7,to_val(7,a)};
    if(s_c)return {6,to_val(6,a)};
    if(s_s)return {5,to_val(5,a)};
    if(san)return {4,to_val(4,a)};
    if(tt)return {3,to_val(3,a)};
    if(two)return {2,to_val(2,a)};
    return {1,to_val(1,a)};
}

pair<pair<int,int>,pair<int,ll>> find_tar(vector<pair<int,int>>a,vector<bool> bl){
    pair<int,ll> maxval = {0,-1};
    pair<int,int> ans;
    for(int i=1;i<=13;i++){
        for(int j=1;j<=4;j++){
            if(bl[i*10+j]){
                vector<pair<int,int>> tp = a;
                tp.push_back({i,j});
                pair<int,ll> tpos = to_pos(tp);
                if(maxval<tpos){maxval = tpos;ans = {i,j};}
            }
        }
    }
    return {ans,maxval};
}

int main(){
    int T;cin>>T;
    while(T--){
        vector<string> ss(8);
        for(int i=0;i<8;i++)cin>>ss[i];//找最大值
        vector<pair<int,int>> a,b;
        for(int i=0;i<8;i++){
            if(i<4)a.push_back(to_p(ss[i]));
            else b.push_back(to_p(ss[i]));
        }
        vector<bool> bl(200,true);
        for(int i=0;i<4;i++){
            int x = a[i].first*10+a[i].second,y = b[i].first*10+b[i].second;
            bl[x]=false;bl[y]=false;
        }
        pair<pair<int,int>,pair<int,ll>> atar = find_tar(a,bl),btar = find_tar(b,bl);
        int x = atar.first.first*10+atar.first.second;bl[x]=false;
        pair<pair<int,int>,pair<int,ll>> aaft = find_tar(a,bl);
        vector<pair<int,int>> tmp = b;tmp.push_back({atar.first.first,atar.first.second});
        pair<int,ll> p0 = btar.second,c1 = atar.second,c2 = aaft.second,p1 = to_pos(tmp);
        //两个最优牌相同
        if(atar.first==btar.first){
            if(p0>c2)cout<<"GeiWoCaPiXie"<<endl;
            else if(p0==c2)cout<<"PaiMeiYouWenTi"<<endl;
            else cout<<"WoYaoYanPai"<<endl;
        }else{
            if(p0>c1||p1>c2)cout<<"GeiWoCaPiXie"<<endl;
            else if(c1>p0&&c2>p1)cout<<"WoYaoYanPai"<<endl;
            else cout<<"PaiMeiYouWenTi"<<endl;
        }
    } 
    return 0;
}