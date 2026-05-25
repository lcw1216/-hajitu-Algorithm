#include<bits/stdc++.h>
using namespace std;
//对于每个c，查询有多少个匹配括号包含不少于x个c
//前缀和预处理字符串
//考虑算法无法预知未来，每次更新字母只更新最近的那个
//然后在出队时间最进的继承到上一个
int main(){
    string s;cin>>s;
    int len = s.length();
    vector<vector<int>> mp,res;
    int l = 0;
    for(int i=0;i<len;i++){
        if(s[i]=='('){
            vector<int> tmp(26,0);
            mp.push_back(tmp);
        }
        if(s[i]==')'){
            res.push_back(mp.back());
            if(mp.size()>=2)for(int i=0;i<26;i++) mp[(int)(mp.size()-2)][i]+=mp.back()[i];
            mp.pop_back();
        }
        if(s[i]<='z'&&s[i]>='a') mp.back()[(int)(s[i]-'a')]++;
    }
    //对res进行预处理，然后逆向dp
    vector<vector<int>> ct(26,vector<int>(1e6,0));
    for(int i=0;i<(int)res.size();i++) for(int j=0;j<26;j++) ct[j][res[i][j]]++;
    for(int i=0;i<26;i++) for(int j=1e6-2;i>=0;i--) ct[i][j]+=ct[i][j+1];
    int Q;cin>>Q;
    while(Q--){
        char c;
        int x,tar;
        cin>>c>>x;
        tar = (int)(c-'0');
        cout<<ct[tar][x]<<endl;
    }
    return 0;
}
