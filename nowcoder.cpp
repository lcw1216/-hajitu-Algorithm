#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//这个复杂度到n*n了
int main(){
    ll T;cin>>T;
    while(T--){
        ll n,m;cin>>n>>m;
        string s;cin>>s;
        ll ans = 0,ng = min(n,m),mans;
        ng = m;
        while(ng--){
        mans = 1;
        char cur;
        if(s[0]=='0'){cur='1';s[0]='1';}
        else {cur = '0';s[0]='0';}
        for(ll i=1;i<n;i++){
            if(s[i]==cur){
                if(cur=='0'){cur='1';s[i]=cur;}
                else if(cur=='1'){cur='0';s[i]=cur;}
                mans++;
            }
        }
        ans+=mans;
        cout<<mans<<endl;
    }
    if(m==min(n,m))cout<<ans-55;
    else {
        ans=ans+(mans*(m-n));
        cout<<ans;
        }
    }
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// int main(){
//     ll T;cin>>T;
//     while(T--){
//         ll n,m;cin>>n>>m;
//         string s;cin>>s;
//         ll ans = 0,ng = min(n,m),mans;
//         while(ng--){
//         mans = 1;
//         char cur;
//         if(s[0]=='0'){cur='1';s[0]='1';}
//         else {cur = '0';s[0]='0';}
//         for(ll i=1;i<n;i++){
//             if(s[i]==cur){
//                 if(cur=='0'){cur='1';s[i]=cur;}
//                 else if(cur=='1'){cur='0';s[i]=cur;}
//                 mans++;
//             }
//         }
//         ans+=mans;
//     }
//     if(m==min(n,m))cout<<ans;
//     else {
//         ans=ans+(mans*(m-n));
//         cout<<ans;
//         }
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;cin>>T;
    while(T--){
        int n,m;cin>>n>>m;
        string s;cin>>s;
        if(n==1){cout<<m<<endl;continue;}
        int l = 0,fg;
        if(s[0]==s[1])fg=0;else fg=1;
        vector<vector<int>> c,d;
        for(int r=0;r<(int)n-1;r++){
            if(s[r]==s[r+1]&&fg==1){
                c.push_back({l,r-1});
                l = r;fg = 0;
            }else if(s[r]!=s[r+1]&&fg==0){
                d.push_back({l,r-1});
                l = r;fg = 1;
            }
            else if(r==n-2){
                if(s[n-1]==s[n-2])c.push_back({l,r+1});
                else d.push_back({l,r+1});
            }
        }
        for(int i=0;i<(int)c.size();i++)cout<<c[i][0]<<' '<<c[i][1]<<endl;
        for(int i=0;i<(int)d.size();i++)cout<<d[i][0]<<' '<<d[i][1]<<endl;
    }
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        string s;cin>>s;
        string t = s;
        string l,r;
        l = s;r = s;
        vector<bool> rr(n,false);
        int ctt = 0;
        bool sam = false;
        for(int i=0;i<n-1;i++){
            if(t[i]<t[i+1]){rr[i] = true;ctt++;}
            else if(t[i]==t[i+1])sam = true;
        }
        int ct = 2;
        if(ctt>1){
            for(int i=0;i<n-1;i++){
                if(t[i]<t[i+1]){
                    swap(t[i],t[i+1]);
                    ct--;
                }
                if(ct==0)break;
                while(i==n-2&&ct>0){
                    swap(t[i],t[i+1]);
                    ct--;
                }
            }

        }
        else if(ctt==1&&sam){
            for(int i=0;i<n-1;i++){
                if(t[i]<t[i+1]){
                    swap(t[i],t[i+1]);
                    break;
                }
            }
        }
        l = t;
        t = s;
        string o = t,tt = t;
        for(int i=0;i<n-2;i++){
            if(t[i]<t[i+2]){
                swap(o[i+1],o[i+2]);
                swap(o[i+1],o[i]);
                swap(tt[i+1],tt[i]);
                swap(tt[i+1],tt[i+2]);
                break;
            }
        }
        if(o>tt)r = o;
        else r = tt;
        if(l == max(s,(max(l,r))))cout<<l<<endl;
        else if(r == max(s,(max(l,r))))cout<<r<<endl;
        else cout<<s<<endl;
    }
    return 0;
}