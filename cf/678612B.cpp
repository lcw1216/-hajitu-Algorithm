#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string to_s(ll a){
    string res;
    if(a==0)res.push_back('0');
    while(a>0){
        if(a%2==1)res.push_back('1');
        else res.push_back('0');
        a/=2;
    }
    reverse(res.begin(),res.end());
    return res;
}
//1最少且数值最小
string to_tlen(string a,string b){
    string res;
    bool at = true;
    for(ll i=1;i<a.length();i++)if(a[i]=='1')at=false;
    if(a.front()=='0'||at)res=a;
    else {
        res.resize(a.length()+1,'0');res[0]='1';
    }
    return res;
}
string to_slen(string a,string b){
    string res;bool fir_dif=true;
    for(ll i=0;i<a.length();i++){
        if(a[i]==b[i])res.push_back(a[i]);
        if(a[i]!=b[i]){
            ll ct = 0;
            for(ll j=i+1;j<a.length();j++)if(a[j]=='1')ct++;
            if(ct<=1)return a;
            else{
                ll pos = 0;
                for(ll j=i+1;j<a.length();j++)if(a[j]=='1'){pos=j;break;}
                a[pos-1]='1';for(ll j=pos;j<a.length();j++)a[j]='0';
                return a;
            }
        }
    }
    return res;
}
ll to_num(string s){
    ll res = 0;
    for(ll i=0;i<s.length();i++){
        if(s[i]=='1')res=res*2+1;
        else res*=2;
    }
    return res;
}
int main(){
    ll a,b;cin>>a>>b;
    string as = to_s(a),bs = to_s(b);
    ll lena = as.length(),lenb = bs.length();
    string res;
    if(lena!=lenb)res = to_tlen(as,bs);
    else res = to_slen(as,bs);
    cout<<to_num(res)<<endl;
    return 0; 
}