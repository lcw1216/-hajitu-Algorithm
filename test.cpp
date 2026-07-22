#include<bits/stdc++.h>
using namespace std;
// 质因数分解
vector<int> to_ys(int tar){
    vector<int> ans;
    for(int i=2;i*i<=tar;i++){
        if(tar%i==0){
            ans.push_back(i);
            while(tar%i==0)tar/=i;
        }
    }
    if(tar>0)ans.push_back(tar);
    return ans;
}
//字符串打表
string to_b(int x){
    string ans;
    while(x>0){
        ans.push_back((char)(x%2+'0'));
        x/=2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
vector<string> to_str(int len){
    vector<string> ans;
    for(int i=1;i<pow(2,len);i++){
        string t = to_b(i);
        if((int)t.length()<len){
            reverse(t.begin(),t.end());
            for(int j=0;j<len-t.length();i++)t.push_back('0');
            reverse(t.begin(),t.end());
        }
        ans.push_back(t);
    }
    return ans;
}
//计算有多少个1 r中的数与n互质
int to_ct(int r,int n){
    vector<int> ys = to_ys(n);
    int len = r,yss = ys.size();
    vector<string> str(yss);
    int slen = str.size();
    for(int i=0;i<slen;i++){
        int ct = 0,tp = 1;
        for(int j=0;j<yss;j++)
            if(str[i][j]=='1'){tp*=ys[j];ct++;}
        if(ct%2==1)len-=tp;else len+=tp;
    }
    return len;
}
//计算有多少个l r中的数与n互质
int to_res(int l,int r,int n){
    int ans = to_ct(r,n);
    if(l>1)ans-=to_ct(l,n);
    return ans;
}
int main(){
    int T;cin>>T;
    while(T--){
        int l,r,n;cin>>l>>r>>n;
        int ans = to_res(l,r,n);
        cout<<ans<<endl;
    }
    return 0;
}